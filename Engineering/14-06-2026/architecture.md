# Real-Time Quiz Platform (10,000 Concurrent Players)

## One-Page Pitch

### Project Overview

The Real-Time Quiz Platform is a web-based application that allows hosts to create and conduct live quizzes while thousands of participants compete simultaneously. The platform supports up to **10,000 concurrent players**, providing instant question delivery, real-time answer submission, live leaderboard updates, and final score calculation.

The system is designed for educational institutions, online competitions, corporate training sessions, and public quiz events where scalability, low latency, and reliability are critical.

---

## Functional Requirements

### Host Features

- Create and manage quizzes
- Add questions and answer options
- Start and end quiz sessions
- View participant statistics
- View final rankings

### Player Features

- Join quiz using a session code
- Receive questions in real time
- Submit answers
- View current score
- View live leaderboard

### System Features

- Real-time question broadcasting
- Real-time leaderboard updates
- Automatic score calculation
- Session management
- Result storage and reporting

---

## Architectural Significant Requirements (ASRs)

### Scalability

- Support at least 10,000 concurrent users in a single quiz session.

### Performance

- Question delivery latency below 200 ms.
- Answer submission acknowledgment below 100 ms.

### Availability

- System availability target of 99.9%.

### Reliability

- No answer submissions should be lost.

### Security

- Secure user authentication.
- Protection against duplicate answer submissions.
- Input validation and API security.

### Maintainability

- Modular microservice-oriented architecture.
- Independent deployment of frontend and backend services.

---

## Database Choice

### PostgreSQL (Primary Database)

Used for persistent data storage:

- Users
- Quizzes
- Questions
- Results
- Historical records

#### Why PostgreSQL?

- ACID compliance
- Strong consistency
- Reliable transactions
- Excellent relational data support

---

### Redis (In-Memory Database)

Used for:

- Active quiz sessions
- Live leaderboard
- Connected players
- Current question state
- Caching frequently accessed data

#### Why Redis?

- Extremely low latency
- Fast read/write operations
- Suitable for real-time workloads
- Supports Pub/Sub communication

---

## Synchronization vs Asynchronization

### Synchronous Operations

The following operations require immediate confirmation:

- User authentication
- Quiz creation
- Quiz joining
- Answer submission acknowledgment

Reason:
The user must know instantly whether the operation succeeded.

---

### Asynchronous Operations

The following operations are processed asynchronously:

- Leaderboard recalculation
- Analytics generation
- Event logging
- Daily report exports
- Notifications

Reason:
These operations are not user-critical and can be processed in the background to improve scalability.

---

## Consistency Model

### Strong Consistency

Used for:

- Answer submissions
- Final scores
- User records

Reason:
Incorrect or lost answers are unacceptable.

---

### Eventual Consistency

Used for:

- Live leaderboard
- Player statistics

Reason:
A small delay of a few milliseconds is acceptable and improves performance under high load.

---

## Frontend and Infrastructure Coupling

### Frontend

Technology Stack:

- React.js
- TypeScript
- Tailwind CSS

Responsibilities:

- User interface
- Quiz participation
- Live leaderboard display
- WebSocket communication

---

### Infrastructure

Technology Stack:

- Nginx Load Balancer
- Docker Containers
- Cloud Virtual Machines
- PostgreSQL
- Redis

Frontend communicates through:

- REST APIs for standard operations
- WebSockets for real-time communication

This design keeps frontend and infrastructure loosely coupled, allowing independent scaling and deployment.

---

## Trade-Offs

### Decision 1: PostgreSQL + Redis

Advantages:

- Strong data integrity
- Fast real-time performance

Disadvantages:

- Additional operational complexity
- Two databases to maintain

---

### Decision 2: WebSockets

Advantages:

- Real-time communication
- Low latency updates

Disadvantages:

- More complex server management
- Persistent connection overhead

---

### Decision 3: Eventual Consistency for Leaderboards

Advantages:

- Better scalability
- Reduced database pressure

Disadvantages:

- Minor delay in leaderboard updates

---

## Deferred Features

The following features are intentionally postponed for future releases:

- AI generated quiz questions
- Voice based quiz participation
- Multi language support
- Video quiz sessions
- Advanced anti cheating mechanisms

---

# C4 Container Diagram

```text
+------------------------------------------------------+
|                   Real-Time Quiz System              |
+------------------------------------------------------+

    +-------------+
    |   Players   |
    +-------------+
           |
           | HTTPS / WebSocket
           v

    +------------------+
    | React Frontend   |
    | (Web Browser)    |
    +------------------+
           |
           |
           v

    +------------------+
    | Nginx Load       |
    | Balancer         |
    +------------------+
           |
     +-----+-----+
     |           |
     v           v

+------------------+     +------------------+
| Quiz Server #1   |     | Quiz Server #2   |
| Node.js +        |     | Node.js +        |
| Socket.IO        |     | Socket.IO        |
+------------------+     +------------------+
          |                     |
          +----------+----------+
                     |
                     v

              +-------------+
              |    Redis    |
              | Sessions &  |
              | Leaderboard |
              +-------------+
                     |
                     v

              +-------------+
              | PostgreSQL  |
              | Users       |
              | Quizzes     |
              | Results     |
              +-------------+

                     |
                     v

              +-------------+
              | Analytics & |
              | Export Jobs |
              +-------------+
```

## Conclusion

The proposed Real-Time Quiz Platform uses a scalable architecture based on React, Node.js, WebSockets, PostgreSQL, and Redis. The design supports 10,000 concurrent users while maintaining low latency, high availability, and reliable score processing. Strong consistency is applied to critical data, while eventual consistency is used where scalability is more important than immediate synchronization.
