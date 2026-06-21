## What is Git?

Git is a distributed version control system created by Linus Torvalds in 2005.

Git allows developers to:

- Track code changes
- Work offline
- Collaborate efficiently
- Maintain complete project history
- Create branches for experimentation

---

# Git vs GitHub Explained

## Git

Git is a software tool installed on your local machine.

Responsibilities:

- Version control
- Commit history
- Branch management
- Local repository management

Example:

```bash
git init
git commit
git branch
```

## GitHub

GitHub is a cloud-based platform that hosts Git repositories online.

Responsibilities:

- Remote repository hosting
- Team collaboration
- Pull requests
- CI/CD integration
- Code reviews

### Simple Analogy

```text
Git = Microsoft Word
GitHub = Google Drive
```

Git creates and manages content locally.

GitHub stores and shares content online.

---

# Git Architecture: Local vs Remote

Git uses two primary environments.

## Local Repository

Stored on your computer.

Contains:

- Source code
- Commit history
- Branches

```text
Developer Machine
      ↓
Local Repository
```

## Remote Repository

Stored on platforms like GitHub.

```text
GitHub Repository
```

Purpose:

- Backup code
- Team collaboration
- Deployment integration

### Workflow

```text
Working Directory
       ↓
Staging Area
       ↓
Local Repository
       ↓
Remote Repository
```

---

# Installing Git (Windows, Mac, Linux)

## Windows

Download Git from:

```text
https://git-scm.com
```

Install using default settings.

## Ubuntu/Linux

```bash
sudo apt update
sudo apt install git
```

## macOS

```bash
brew install git
```

Verify installation:

```bash
git --version
```

---

# Terminal Setup & Verifying Installation

Check Git installation:

```bash
git --version
```

Example output:

```text
git version 2.45.0
```

If Git returns a version number, installation is successful.

---

# Creating a Local Project & Files

Create a project:

```bash
mkdir git-demo
cd git-demo
```

Create files:

```bash
touch index.html
touch app.js
```

Project structure:

```text
git-demo/
├── index.html
└── app.js
```

---

# git init: Initializing a Repository

Convert a folder into a Git repository:

```bash
git init
```

Output:

```text
Initialized empty Git repository
```

Git creates a hidden folder:

```text
.git/
```

This folder stores:

- Commits
- Branches
- Configuration
- Repository history

---

# Creating a Remote Repository on GitHub

Steps:

1. Login to GitHub
2. Click New Repository
3. Enter repository name
4. Click Create Repository

Example:

```text
my-first-project
```

GitHub generates a repository URL:

```text
https://github.com/username/my-first-project.git
```

---

# git clone: Cloning a Repository

Clone an existing repository:

```bash
git clone https://github.com/username/project.git
```

Example:

```bash
git clone https://github.com/john/demo.git
```

Git downloads:

- Source code
- Commit history
- Branches

---

# git status: Tracking Changes

Check repository status:

```bash
git status
```

Shows:

- Modified files
- New files
- Deleted files
- Staged changes

Example:

```text
modified: app.js
untracked: style.css
```

---

# git add: Staging Changes

Move changes to the staging area.

Stage a file:

```bash
git add app.js
```

Stage multiple files:

```bash
git add index.html app.js
```

Git is now tracking those changes for the next commit.

---

# git add Variations (., -A, Specific Files)

## Add Specific File

```bash
git add app.js
```

Adds only app.js.

---

## Add Current Directory

```bash
git add .
```

Adds all changes in the current directory.

---

## Add Everything

```bash
git add -A
```

Stages:

- New files
- Modified files
- Deleted files

Across the entire repository.

---

# git reset: Unstaging Files

Remove files from the staging area.

Example:

```bash
git reset app.js
```

Result:

```text
Staged → Unstaged
```

The file remains unchanged on disk.

Only the staging status changes.

---

# git commit: Saving Changes Permanently

A commit creates a snapshot of your project.

Example:

```bash
git commit -m "Add login page"
```

Commit message should clearly describe the changes.

---

# Configuring Git User Name & Email

Git uses author information for commits.

Set globally:

```bash
git config --global user.name "Muhammad Farooq"
```

```bash
git config --global user.email "your@email.com"
```

Verify:

```bash
git config --list
```

Set locally:

```bash
git config --local user.name "Muhammad Farooq"
```

```bash
git config --local user.email "your@email.com"
```

Verify:

```bash
git config --list
```

---

# git reset HEAD: Undoing Last Commit

Undo the most recent commit while keeping changes:

```bash
git reset HEAD~1
```

or

```bash
git reset HEAD~
```

Result:

```text
Last commit removed
Files remain available
```

Useful when:

- Wrong commit message
- Committed too early
- Forgot to include files

---

# git rm: Deleting Files

Delete file from:

- Working directory
- Git tracking enabled automatically

Example:

```bash
git rm app.js
```

---

# git rm --cached: Stop Tracking Files

Keep the file locally but remove it from Git tracking.

Example:

```bash
git rm --cached .env
```

Useful for:

```text
.env
node_modules
secret files
configuration files
```

---

# git log: Viewing Commit History

View commit history:

```bash
git log
```

Example:

```text
commit a123bc
Author: Muhammad Farooq
Date: ...

Add authentication
```

### Compact Log

```bash
git log --oneline
```

Output:

```text
a123bc Add login feature
b456de Create navbar
c789fg Initial commit
```

Useful for quickly reviewing project history.

---

## Git Branching Explained

Branching in Git allows you to create separate lines of development. Each branch works independently so you can build features without affecting main code.

### Commands:

```bash
git branch branch-name
git checkout branch-name
git switch branch-name
```

---

## git checkout: Switching Branches

Used to switch between branches or view old commits.

### Command:

```bash
git checkout branch-name
```

or modern way:

```bash
git switch branch-name
```

---

## git merge: Combining Branches

Used to combine one branch into another.

### Command:

```bash
git checkout main
git merge feature-branch
```

---

## Resolving Merge Conflicts

When Git cannot auto-merge changes, conflict occurs. You must manually fix it.

---

## Checking Out Previous Commits (Time Travel)

Used to move back to old commits.

### Command:

```bash
git checkout commit-id
```

---

## git diff: Comparing Changes

Shows differences between files, commits, or branches.

### Commands:

```bash
git diff
git diff branch1 branch2
```

---

## Understanding Push, Fetch, and Pull

- push → send changes to GitHub
- fetch → download changes only
- pull → download + merge changes

---

## git push: Uploading to GitHub

### Command:

```bash
git push origin main
```

---

## git fetch vs git pull

- fetch → only downloads updates
- pull → downloads + merges updates

### Commands:

```bash
git fetch
git pull
```

---

## git restore: Discarding Local Changes

### Command:

```bash
git restore filename
```

---

## git stash: Saving Unfinished Work

### Commands:

```bash
git stash
git stash pop
```

---

## git revert: Undoing Commits Safely

### Command:

```bash
git revert commit-id
```

---

## git rebase: Cleaning Up History

### Command:

```bash
git rebase main
```

---

## Pull Requests (PR) & Collaboration

Used for:

- Code review
- Team collaboration
- Merging features into main branch

---
