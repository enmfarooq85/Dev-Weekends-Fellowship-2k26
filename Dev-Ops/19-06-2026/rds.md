# AWS RDS and API Gateway Guide

# What is AWS RDS?

Amazon Relational Database Service (RDS) is a managed database service provided by AWS that simplifies the setup, operation, scaling, and maintenance of relational databases in the cloud.

Instead of managing database servers manually, AWS handles most operational tasks for you.

### Supported Database Engines

* MySQL
* PostgreSQL
* MariaDB
* Oracle Database
* Microsoft SQL Server
* Amazon Aurora

---

# Why Do We Use RDS?

AWS RDS provides several advantages over self-managed databases.

## Automated Backups

AWS automatically creates backups and allows point-in-time recovery.

## High Availability

RDS supports Multi-AZ deployments to improve availability and fault tolerance.

## Automatic Patching

AWS handles operating system and database patch updates.

## Scalability

Resources such as CPU, memory, and storage can be scaled easily.

## Monitoring

Integration with CloudWatch provides detailed performance metrics and monitoring.

## Security

Supports:

* VPC isolation
* IAM integration
* Encryption at rest
* Encryption in transit

## Reduced Operational Overhead

Developers can focus on application development rather than database administration.

---

# What are Lambda Functions?

AWS Lambda is a serverless computing service that allows you to run code without managing servers.

You upload your code, and AWS executes it whenever an event occurs.

### Key Characteristics

* No server management
* Pay only for usage
* Automatic scaling
* Event-driven execution

### Supported Languages

* JavaScript (Node.js)
* Python
* Java
* Go
* .NET
* Ruby

---

# What is API Gateway?

Amazon API Gateway is a fully managed service that allows developers to create, publish, secure, monitor, and manage APIs.

It acts as an entry point for client requests and routes them to backend services.

### Supported API Types

* REST APIs
* HTTP APIs
* WebSocket APIs

---

# Why Do We Use API Gateway?

API Gateway provides a centralized layer between clients and backend services.

## Security

Supports:

* Authentication
* Authorization
* API Keys
* IAM Integration
* Rate Limiting

## Traffic Management

Handles thousands of requests efficiently.

## Monitoring

Provides logs and metrics through CloudWatch.

## Request Validation

Validates incoming requests before forwarding them to backend services.

## Scalability

Automatically scales based on traffic demand.

## Integration with AWS Services

Works seamlessly with:

* Lambda
* ECS
* EC2
* DynamoDB
* SQS

---

# Real-World Example: Food Delivery Application

Suppose we have a food delivery application.

### Without API Gateway

```text
Mobile App
    ↓
Directly Calls Multiple Services

Order Service
Payment Service
Notification Service
User Service
```

Problems:

* Multiple endpoints to manage
* Difficult security configuration
* No centralized monitoring
* Increased complexity

---

### With API Gateway

```text
Mobile App
      ↓
 API Gateway
      ↓
 -------------------
 |        |        |
 ↓        ↓        ↓
User   Order   Payment
Service Service Service
             ↓
         AWS Lambda
```

Benefits:

* Single entry point
* Centralized authentication
* Request validation
* Monitoring and logging
* Rate limiting
* Easier maintenance

---
