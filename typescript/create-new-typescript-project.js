#!/usr/bin/env node

const fs = require('fs');
const path = require('path');

// 1. Get project name from command line arguments
const projectName = process.argv[2];

if (!projectName) {
	console.error('Error: Please provide a project name.');
	console.log(
		'Usage: node create-new-typescript-project-script.js <project-name>'
	);
	process.exit(1);
}

// 2. Define the full path for the new project directory
const projectDir = path.resolve(process.cwd(), projectName);

// 3. Check if directory already exists
if (fs.existsSync(projectDir)) {
	console.error(`Error: Directory '${projectName}' already exists.`);
	process.exit(1);
}

// 4. Create the new project directory
try {
	fs.mkdirSync(projectDir);
	console.log(`📁 Created directory: ${projectName}`);
} catch (err) {
	console.error(`Error creating directory: ${err.message}`);
	process.exit(1);
}

// 5. Define content for main.ts
const mainTsContent = `
console.log("Hello, TypeScript!");

// To test the start script, you can run:
// npm install
// npm start
`;

// 6. Define content for package.json
const packageJsonContent = {
	name: projectName,
	version: '1.0.0',
	description: 'A simple TypeScript project',
	main: 'dist/main.js',
	scripts: {
		// 'build' script compiles TypeScript to JavaScript
		build: 'tsc',
		// 'start' script first builds, then runs the compiled JavaScript
		start: 'npm run build && node dist/main.js',
	},
	devDependencies: {
		// TypeScript is required to compile .ts files
		typescript: '^5.0.0',
	},
};

// 7. Define content for tsconfig.json
// This file tells the TypeScript compiler (tsc) how to behave
const tsConfigContent = {
	compilerOptions: {
		target: 'ES2020', // Compile to modern JavaScript
		module: 'commonjs', // Use CommonJS modules (for Node.js)
		rootDir: './', // The root directory of source files
		outDir: './dist', // Where to output compiled JavaScript
		esModuleInterop: true, // Allows better compatibility with different module types
		strict: true, // Enforces strict type-checking
		skipLibCheck: true, // Skips type checking of declaration files
	},
	include: [
		'main.ts', // Explicitly tell tsc to only compile main.ts
	],
};

// 8. Write the files
try {
	// Write main.ts
	fs.writeFileSync(path.join(projectDir, 'main.ts'), mainTsContent.trim());
	console.log('   📄 Created main.ts');

	// Write package.json
	fs.writeFileSync(
		path.join(projectDir, 'package.json'),
		JSON.stringify(packageJsonContent, null, 2)
	);
	console.log('   📄 Created package.json');

	// Write tsconfig.json
	fs.writeFileSync(
		path.join(projectDir, 'tsconfig.json'),
		JSON.stringify(tsConfigContent, null, 2)
	);
	console.log('   📄 Created tsconfig.json');

	// 9. Show success message and next steps
	console.log(`\n✅ Project '${projectName}' created successfully!`);
	console.log('\nNext steps:');
	console.log(`  1. cd ${projectName}`);
	console.log('  2. npm install  (to install TypeScript)');
	console.log('  3. npm start    (to run your project)');
} catch (err) {
	console.error(`Error writing files: ${err.message}`);
	// Attempt to clean up directory if file writing fails
	fs.rmdirSync(projectDir, { recursive: true });
	console.log(`Cleaned up directory: ${projectName}`);
}
