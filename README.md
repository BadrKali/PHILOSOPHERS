<h1>Dining Philosophers Problem Simulation with Threads and Mutexes</h1>

<p>This project is a simulation of the famous Dining Philosophers Problem, implemented using threads as philosophers and mutexes as forks. The Dining Philosophers Problem is a classic synchronization problem in computer science that illustrates the challenges of resource allocation and deadlock avoidance in concurrent systems.</p>

<p>The simulation provides a visual representation of the problem, where philosophers (represented as threads) sit around a circular table, and forks (represented as mutexes) are placed between each pair of philosophers. The objective is to allow the philosophers to share the forks (resources) in a way that avoids deadlocks and ensures fairness.</p>

<h2>Key Features:</h2>
<ol>
  <li><strong>Thread-Based Philosophers:</strong> Each philosopher is implemented as a separate thread, allowing concurrent execution and mimicking real-world scenarios.</li>
  <li><strong>Mutex-Based Forks:</strong> Mutexes are used to represent forks, ensuring mutual exclusion when philosophers try to pick them up.</li>
  <li><strong>Deadlock Avoidance:</strong> The simulation employs a deadlock avoidance strategy to prevent philosophers from entering into a deadlock state, where they are unable to acquire the necessary forks to eat.</li>
  <li><strong>Fair Resource Allocation:</strong> The implementation strives to allocate forks fairly among philosophers, preventing starvation and ensuring that each philosopher gets a chance to eat.</li>
</ol>
