# Docker Basics Guide

## 1. What is VM and Containerization

A **Virtual Machine (VM)** is a full computer system that runs inside another computer. It has its own operating system, memory, and storage.

**Containerization** is a lightweight way to run applications where everything (code + dependencies) runs in isolated containers but shares the same OS kernel.

👉 VMs are heavy  
👉 Containers are fast and lightweight

---

## 2. What is Docker

**Docker** is a tool that helps us create, run, and manage containers easily.

It packages an application with all its dependencies into a container so it can run anywhere.

---

## 3. Why we use Docker

We use Docker because:

- It works the same on every system
- Easy deployment
- Fast setup
- No “it works on my machine” problem
- Lightweight compared to VMs

---

## 4. What happens if we do NOT use Docker

Without Docker:

- Different environments cause errors
- Hard to manage dependencies
- Deployment becomes complex
- App may work on one system but fail on another
- Setup time increases

---

## 5. When should we use Docker

We should use Docker when:

- Building web applications
- Working in a team
- Deploying apps to servers
- Microservices architecture
- Need consistent environment

---

## 6. What is Docker Registry

A **Docker Registry** is a storage system where Docker images are stored and shared.

Example:

- Docker Hub (most popular)
- AWS ECR
- Google Container Registry

👉 Think of it like GitHub for Docker images

---

## 7. Docker Architecture

Docker has 3 main parts:

- **Docker Client** → where we write commands
- **Docker Daemon (Server)** → builds and runs containers
- **Docker Registry** → stores images

Flow:
Client → Daemon → Images → Containers → Registry

---

## 8. Difference between Image and Container

| Image                     | Container              |
| ------------------------- | ---------------------- |
| Blueprint of app          | Running instance       |
| Read-only                 | Writable               |
| Used to create containers | Actual running process |
| Stored in registry        | Runs on system         |

---

## 9. How to build and push Docker image

### Step 1: Build Image

```bash
docker build -t username/image-name:tag .
```

### Step 2: Login to Docker Hub

```bash
docker login
```

### Step 3: Tag Image

```bash
docker tag image-name username/image-name:tag
```

### Step 4: Push Image

```bash
docker push username/image-name:tag
```

## Basic Docker Commands

```bash
docker --version
docker info

docker pull image-name
docker images

docker run image-name
docker run -d image-name
docker run -p 8080:80 image-name

docker ps
docker ps -a

docker stop container-id
docker start container-id
docker restart container-id

docker rm container-id
docker rmi image-id

docker exec -it container-id bash

docker build -t image-name .

docker login
docker push username/image-name:tag
