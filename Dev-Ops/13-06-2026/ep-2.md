# Domain, Route 53, Linux, and Git Guide

## What is a Domain?

A domain is a human readable name that identifies a website address on the internet. Instead of using an IP address, users can access websites using a simple and memorable name.

Examples:

* google.com
* github.com
* amazon.com

A domain acts as a shortcut, that points users to the server where the website is hosted.

---

## Why Do We Need a Domain?

Domains are important because:

### Easy to Remember

Humans can remember names more easily than numerical IP addresses.

Example:

```
google.com
```

is easier to remember than:

```
142.250.190.14
```

### Branding

A custom domain helps establish a professional online identity.

Examples:

* mycompany.com
* myportfolio.com

### Flexibility

If a server's IP address changes, the domain can simply be updated to point to the new IP without affecting users.

### Better User Experience

Users trust and recognize branded domain names more than IP addresses.

---

## Can We Use Just the Public IP Address of a Website?

Yes, websites can technically be accessed directly through a public IP address.

Example:

```
http://203.0.113.10
```

However, using only an IP address is not recommended because:

* IP addresses are difficult to remember.
* They provide no branding.
* SSL certificates are typically associated with domain names.
* IP addresses may change over time.
* Hosting multiple websites on a single IP becomes difficult.

For these reasons, domains are preferred over direct IP access.

---

## Domain Name Basics

A domain name consists of several parts.

Example:

```
www.example.com
```

### Top-Level Domain (TLD)

```
.com
```

Examples:

* .com
* .org
* .net
* .io

### Second-Level Domain

```
example
```

This is usually the business or website name.

### Subdomain

```
www
```

Other examples:

```
blog.example.com
api.example.com
admin.example.com
```

### DNS (Domain Name System)

DNS translates domain names into IP addresses so browsers can locate servers.

Example:

```
google.com → 142.250.190.14
```

---

# What is Route 53?

Route 53 is Amazon Web Services (AWS)' highly available and scalable Domain Name System (DNS) service.

It helps route internet traffic to applications and resources hosted on AWS or other platforms.

The name "Route 53" comes from:

* Route = Routing internet traffic
* 53 = Standard DNS port number

---

# Benefits Provided by Route 53

### High Availability

AWS provides reliable DNS infrastructure distributed worldwide.

### Scalability

Can handle millions of DNS requests efficiently.

### Domain Registration

You can purchase and manage domain names directly through Route 53.

### DNS Management

Allows management of:

* A Records
* CNAME Records
* MX Records
* TXT Records
* NS Records

### Health Checks

Route 53 can monitor application health and redirect traffic when failures occur.

### Traffic Routing Policies

Supports:

* Simple Routing
* Weighted Routing
* Latency Routing
* Geolocation Routing
* Failover Routing

### Integration with AWS Services

Works seamlessly with:

* EC2
* Load Balancers
* CloudFront
* S3
* API Gateway

---

# How to Setup a Domain to an IP Address

Suppose:

```
Domain: mywebsite.com
Server IP: 54.123.45.67
```

### Step 1: Purchase a Domain

Buy a domain from:

* Route 53
* Namecheap
* GoDaddy

### Step 2: Create a Hosted Zone

In Route 53:

```
Route 53
→ Hosted Zones
→ Create Hosted Zone
```

Enter:

```
mywebsite.com
```

### Step 3: Create an A Record

Create a DNS record:

```
Type: A
Value: 54.123.45.67
```

This maps the domain to the server IP.

### Step 4: Update Name Servers

If the domain was purchased from another registrar:

1. Copy Route 53 Name Servers.
2. Update them in your registrar dashboard.

Example:

```
ns-123.awsdns.com
ns-456.awsdns.net
ns-789.awsdns.org
ns-101.awsdns.co.uk
```

### Step 5: Wait for DNS Propagation

DNS changes typically take:

```
5 minutes to 48 hours
```

### Verification

```
ping mywebsite.com
```

Expected output:

```
54.123.45.67
```

The domain now points to your server.

---

# Linux Basic Commands

## Navigation

```bash
pwd
```

Print current directory.

```bash
ls
```

List files.

```bash
ls -la
```

Show detailed files including hidden files.

```bash
cd folder-name
```

Move into a directory.

```bash
cd ..
```

Move back one directory.

---

## File Operations

```bash
touch file.txt
```

Create a file.

```bash
mkdir project
```

Create a directory.

```bash
rm file.txt
```

Delete a file.

```bash
rm -rf folder
```

Delete a folder recursively.

```bash
cp source.txt destination.txt
```

Copy files.

```bash
mv old.txt new.txt
```

Move or rename files.

---

## Viewing Files

```bash
cat file.txt
```

Display file contents.

```bash
less file.txt
```

View file page by page.

```bash
head file.txt
```

View first lines.

```bash
tail file.txt
```

View last lines.

---

## Permissions

```bash
chmod 755 file.sh
```

Change permissions.

```bash
chown user:user file.txt
```

Change ownership.

---

## Networking

```bash
ping google.com
```

Check connectivity.

```bash
curl https://example.com
```

Make HTTP requests.

```bash
netstat -tulpn
```

View listening ports.

---

# Rebasing vs Merging

Both are used to integrate changes from one branch into another.

## Git Merge

Example:

```bash
git checkout main
git merge feature
```

Result:

```
A---B---C
     \   \
      D---E
```

Advantages:

* Preserves complete history.
* Safer for shared branches.
* Easy to understand.

Disadvantages:

* Creates merge commits.
* History may become cluttered.

---

## Git Rebase

Example:

```bash
git checkout feature
git rebase main
```

Result:

```
A---B---C---D'---E'
```

Advantages:

* Cleaner history.
* Linear commit timeline.
* Easier to read.

Disadvantages:

* Rewrites commit history.
* Can be dangerous on shared branches.

---

## When to Use Which?

Use Merge when:

* Working on shared branches.
* Preserving history is important.

Use Rebase when:

* Cleaning up feature branch history.
* Preparing commits before merging.

---

# Git Cherry Pick

Cherry pick allows copying a specific commit from one branch and applying it to another branch.

Example:

```bash
git cherry-pick abc123
```

Where:

```
abc123
```

is the commit hash.

---

## Use Case

Suppose:

```
feature-login
```

contains 10 commits, but you only need one bug fix commit in another branch.

Instead of merging the entire branch:

```bash
git cherry-pick abc123
```

Only the selected commit will be copied.

---

## Example Workflow

```bash
git checkout main
git cherry-pick abc123
```

Result:

The changes from commit `abc123` are applied to the current branch.

---

## Benefits of Cherry Pick

* Reuse specific commits.
* Move bug fixes quickly.
* Avoid unnecessary merges.
* Keep branches independent.

---

# Conclusion

This guide covered:

* Domain fundamentals
* DNS basics
* AWS Route 53
* Mapping domains to IP addresses
* Essential Linux commands
* Git Merge vs Rebase
* Git Cherry Pick

These concepts are fundamental for DevOps, cloud deployment, backend development, and modern software engineering workflows.
