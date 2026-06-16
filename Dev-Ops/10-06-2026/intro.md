# A Comprehansive Guide to AWS: Bridging the Gap Between Development and Operations

## Table of Contents

1. What Happened Before Cloud Computing?
2. What is AWS?
3. Why Do We Need AWS?
4. Basic AWS Services Every Developer Should Know
5. What is EC2?
6. Why Do We Use EC2?
7. Understanding EC2 Instances
8. Requirements Before Creating an EC2 Instance
   - Operating System (OS)
   - Instance Type
   - Storage (Volume)
   - Security Group
   - Key Pair
9. Launching an EC2 Instance
10. Connecting to Your EC2 Server
11. Understanding Your EC2 Server
12. Preparing the Server for Deployment
13. Deploying Your Application

---

# What Happened Before Cloud Computing?

Before cloud computing became popular, companies followed a traditional infrastructure model.

## Traditional Approach

A company had to:

1. Purchase physical servers.
2. Set up networking equipment.
3. Rent data center space.
4. Install operating systems manually.
5. Manage backups.
6. Handle hardware failures.
7. Upgrade machines when traffic increased.

### Problems

- Very expensive
- Time-consuming
- Difficult to scale
- Hardware maintenance required
- Risk of downtime

---

# What is AWS?

AWS (Amazon Web Services) is a cloud computing platform provided by Amazon that allows developers and companies to rent computing resources instead of purchasing and maintaining physical hardware.

AWS provides services such as:

- Virtual Servers
- Databases
- Storage
- Networking
- Security
- Machine Learning
- Monitoring Tools

Instead of buying expensive computers and servers, businesses can use AWS resources on demand and pay only for what they use.

---

# Why Do We Need AWS?

Modern applications need:

- High availability
- Scalability
- Security
- Global access
- Easy deployment

Without cloud providers, companies would need to:

- Buy physical servers
- Rent data centers
- Manage hardware failures
- Handle networking manually
- Upgrade infrastructure themselves

AWS solves these problems by providing ready-to-use cloud infrastructure.

---

# Basic AWS Services Every Developer Should Know

## EC2 (Elastic Compute Cloud)

Virtual servers in the cloud.

## S3 (Simple Storage Service)

Object storage for files and media.

## RDS (Relational Database Service)

Managed SQL databases.

## DynamoDB

Managed NoSQL database.

## CloudWatch

Monitoring and logging service.

## IAM (Identity and Access Management)

User permissions and access control.

## Route 53

DNS and domain management service.

---

# What is EC2?

EC2 stands for:

**Elastic Compute Cloud**

It is a service that provides virtual servers in AWS.

An EC2 instance behaves like a remote computer that runs in Amazon's data centers.

You can:

- Install software
- Run applications
- Host websites
- Deploy APIs
- Connect databases
- Execute scripts

---

# Why Do We Use EC2?

EC2 allows us to:

- Host web applications
- Deploy backend servers
- Run Node.js applications
- Run React applications
- Host databases
- Execute automation tasks

Instead of buying a physical computer, AWS provides a virtual computer on demand.

---

# Understanding EC2 Instances

An EC2 Instance is simply a virtual machine running in AWS.

Think of it as:

> A remote computer that you can access through SSH.

Examples:

- Ubuntu Server
- Amazon Linux
- Windows Server

Once launched, you can install:

- Node.js
- Nginx
- Docker
- Databases
- Any development tools

---

# Requirements Before Creating an EC2 Instance

Before launching an EC2 instance, you must choose several configurations.

---

## 1. Operating System (AMI)

AMI stands for:

**Amazon Machine Image**

It determines the operating system installed on the server.

Common choices:

### Ubuntu Server

Recommended for most Node.js developers.

Advantages:

- Beginner-friendly
- Large community
- Extensive documentation

### Amazon Linux

Optimized for AWS environments.

### Windows Server

Used for .NET and Windows applications.

Recommended Choice:

```text
Ubuntu Server LTS
```

---

## 2. Instance Type

Instance type determines:

- CPU
- RAM
- Performance

Examples:

### t2.micro

- 1 vCPU
- 1 GB RAM

### t3.micro

- Better performance
- Common beginner choice

### t3.small

- More RAM
- Suitable for medium-sized projects

Recommended for learning:

```text
t2.micro
or
t3.micro
```

---

## 3. Storage (Volume)

Storage is the hard drive attached to the server.

AWS uses EBS (Elastic Block Store).

---

# Understanding Inbound and Outbound Rules

AWS Security Groups act as a virtual firewall for your EC2 instance.

They control:

- Incoming traffic (Inbound Rules)
- Outgoing traffic (Outbound Rules)

---

## Inbound Rules

Inbound Rules determine:

> Who can access your server and through which ports.

Example:

| Type       | Protocol | Port | Source               |
| ---------- | -------- | ---- | -------------------- |
| SSH        | TCP      | 22   | Your IP              |
| HTTP       | TCP      | 80   | 0.0.0.0/0            |
| HTTPS      | TCP      | 443  | 0.0.0.0/0            |
| Custom TCP | TCP      | 3000 | 0.0.0.0/0 (optional) |

### Common Ports

#### Port 22 (SSH)

Used to connect to your EC2 server using SSH.

Example:

```bash
ssh -i key.pem ubuntu@your-public-ip
```

Without Port 22 access, you cannot log in to the server.

---

#### Port 80 (HTTP)

Used for normal website traffic.

Example:

```text
http://your-domain.com
```

or

```text
http://your-public-ip
```

---

#### Port 443 (HTTPS)

Used for secure encrypted website traffic.

Example:

```text
https://your-domain.com
```

SSL certificates require this port.

---

#### Port 3000

Commonly used by Node.js applications.

Example:

```javascript
app.listen(3000);
```

For production deployments, this port is usually accessed only by Nginx and not exposed publicly.

---

## Outbound Rules

Outbound Rules determine:

> Where your EC2 server can send requests.

Examples:

- Downloading packages
- Installing Node.js
- Pulling code from GitHub
- Calling external APIs
- Connecting to databases

By default AWS allows:

| Type        | Protocol | Port | Destination |
| ----------- | -------- | ---- | ----------- |
| All Traffic | All      | All  | 0.0.0.0/0   |

This means your server can communicate with any destination on the internet.

---

## Example Deployment Flow

Suppose:

- User visits your website.
- Nginx is running on Port 80.
- Node.js application is running on Port 3000.

Request flow:

```text
Browser
   ↓
Port 80 (HTTP)
   ↓
Nginx
   ↓
Port 3000
   ↓
Node.js Application
```

In this case:

### Inbound Rules

```text
22  → SSH Access
80  → HTTP Access
443 → HTTPS Access
```

### Outbound Rules

```text
Allow All Traffic
```

---

## Best Practice

For Production:

### Inbound Rules

```text
SSH (22)      → Your IP Only
HTTP (80)     → Anywhere
HTTPS (443)   → Anywhere
```

### Outbound Rules

```text
Allow All Traffic
```

---

## Security Tip

Avoid exposing your Node.js application directly.

Instead of:

```text
Internet → Port 3000 → Node.js
```

Use:

```text
Internet → Nginx (80/443) → Node.js (3000)
```

This provides:

- Better Security
- SSL Support
- Reverse Proxying
- Load Balancing
- Easier Production Deployment

## 5. Key Pair

A Key Pair is used for secure SSH access.

AWS generates:

- Public Key
- Private Key

You download the `.pem` file.

Example:

```text
my-server.pem
```

Keep this file safe.

Without it, you cannot connect to the server.

---

# Launching an EC2 Instance

Steps:

1. Open AWS Console.
2. Navigate to EC2 Dashboard.
3. Click "Launch Instance".
4. Enter instance name.
5. Select Ubuntu Server.
6. Select instance type.
7. Create or select a key pair.
8. Configure storage.
9. Configure security groups.
10. Click Launch Instance.

AWS will now create your virtual server.

---

# Connecting to Your EC2 Server

After launching the instance:

1. Open EC2 Dashboard.
2. Select your instance.
3. Click Connect.
4. Copy the SSH command.

Example:

```bash
ssh -i "my-server.pem" ubuntu@ec2-public-ip.amazonaws.com
```

Before connecting:

```bash
chmod 400 my-server.pem
```

Connect:

```bash
ssh -i "my-server.pem" ubuntu@ec2-public-ip.amazonaws.com
```

If successful, you will enter your EC2 machine.

---

# Understanding Your EC2 Server

Once connected:

```bash
ubuntu@ip-172-31-x-x:~$
```

You are now inside your remote Linux machine.

Think of it as:

> A virtual laptop running in AWS.

You can now:

- Create files
- Install software
- Deploy applications
- Configure web servers

---

# Preparing the Server for Deployment

Update the server:

```bash
sudo apt update
sudo apt upgrade
```

Install essential tools:

```bash
sudo apt install git
```

Install Node.js using NVM:

```bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/master/install.sh | bash
```

Reload shell:

```bash
source ~/.bashrc
```

Install Node.js:

```bash
nvm install --lts
```

Verify:

```bash
node -v
npm -v
```

Install Nginx:

```bash
sudo apt install nginx
```

Start Nginx:

```bash
sudo systemctl start nginx
sudo systemctl enable nginx
```

Install PM2:

```bash
npm install -g pm2
```

Now your server is ready for deployment.

---

# Deploying Your Application

Now that the server is ready, the next step is to deploy your application.

---

## Step 1: Clone Your Repository

### If the Repository is Public

Simply clone the repository:

```bash
git clone https://github.com/username/project-name.git
```

Example:

```bash
git clone https://github.com/enmfarooq85/node-js-app.git
```

---

### If the Repository is Private

GitHub will not allow direct access without authentication.

You have two common options:

#### Option 1: Personal Access Token (Recommended)

Generate a Personal Access Token (PAT) from GitHub.

Navigate to:

```text
GitHub → Settings → Developer Settings → Personal Access Tokens
```

Generate a token with repository access.

Clone using:

```bash
git clone https://YOUR_TOKEN@github.com/username/project-name.git
```

Example:

```bash
git clone https://ghp_xxxxxxxxxxxxxxxxxxxx@github.com/enmfarooq85/private-app.git
```

> Never share or commit your token publicly.

---

#### Option 2: SSH Authentication

Generate an SSH key on the server:

```bash
ssh-keygen -t ed25519 -C "your-email@example.com"
```

Display the public key:

```bash
cat ~/.ssh/id_ed25519.pub
```

Copy the key and add it to GitHub:

```text
GitHub → Settings → SSH and GPG Keys
```

Now clone using SSH:

```bash
git clone git@github.com:username/project-name.git
```

---

## Step 2: Navigate to the Project Directory

Move into the project folder:

```bash
cd project-name
```

Example:

```bash
cd node-js-app
```

Verify files:

```bash
ls
```

You should see files such as:

```text
package.json
package-lock.json
src/
public/
```

---

## Step 3: Install Dependencies

Install all required packages:

```bash
npm install
```

or

```bash
npm i
```

This command reads the package.json file and installs all project dependencies.

---

## Step 4: Configure Environment Variables

Many applications require environment variables.

Create a .env file:

```bash
nano .env
```

Example:

```env
PORT=3000
MONGODB_URI=your_database_url
JWT_SECRET=your_secret_key
```

Save and exit.

---

## Step 5: Test the Application

Start the application manually:

```bash
npm run dev
```

or

```bash
npm start
```

If everything is configured correctly, the application should start successfully.

---

## Step 6: Verify the Application

Check if the application is listening on the expected port.

Example:

```bash
curl http://localhost:3000
```

If the application responds, the server is working correctly.

---

## Step 7: Run the Application Using PM2

Instead of running the application directly, use PM2.

Start the application:

or

```bash
pm2 start server.js --name "my-app"
```

Verify:

```bash
pm2 list
```

View logs:

```bash
pm2 logs
```

---

## Deployment Flow Summary

```text
Create EC2 Instance
        ↓
Connect via SSH
        ↓
Update Server
        ↓
Install Node.js, Nginx, PM2
        ↓
Clone Repository
        ↓
Install Dependencies
        ↓
Configure Environment Variables
        ↓
Test Application
        ↓
Run with PM2
        ↓
Configure Nginx Reverse Proxy
        ↓
Access Application via Public IP or Domain
```
