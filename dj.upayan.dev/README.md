# dj.upayan.dev

[![Site](https://img.shields.io/badge/dj.upayan.dev-1e3a8a?style=for-the-badge&logo=internet-explorer&logoColor=white)](https://dj.upayan.dev)

## Overview

`dj.upayan.dev` is a web application that serves as a browsing interface for the entire repository. It allows users to navigate through various projects, view file contents, and access documentation directly from their browser.

## Features

- **Directory Listing**: Browse through the directory structure of the repository.
- **File Viewing**: View the contents of files with syntax highlighting.
- **Breadcrumb Navigation**: Easily navigate back to previous directories.
- **GitHub Integration**: View files and directories on GitHub with a single click.

## Getting Started

To run the server locally, follow these steps:

1. Clone the repository:

    ```sh
    git clone https://github.com/upayanmazumder/DevJourney.git
    cd DevJourney/dj.upayan.dev
    ```

2. Install dependencies:

    ```sh
    npm install
    ```

3. Start the server:

    ```sh
    npm start
    ```

4. Open your browser and navigate to `http://localhost:3000`.

## Usage

- **Home Page**: The home page displays the root directory of the repository.
- **Directory Listing**: Click on directories to navigate into them.
- **File Viewing**: Click on files to view their contents with syntax highlighting.
- **Breadcrumb Navigation**: Use the breadcrumb links at the top to navigate back to previous directories.
- **GitHub Integration**: Click the "View on GitHub" button to view the current directory or file on GitHub.

## Deployment

The application can be deployed to any platform that supports Node.js. The following environment variables are required for deployment:

- `GITHUB_TOKEN`: A GitHub token with read access to the repository.

## License

This project is licensed under the MIT License. See the [LICENSE](../LICENSE) file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request on GitHub.

## Contact

For any questions or feedback, please contact [Upayan Mazumder](https://github.com/upayanmazumder)
