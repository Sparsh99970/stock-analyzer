#Stock Analyzer (C++)

A lightweight real-time stock analysis tool built in C++ that helps you compute:

Stock Span
Maximum price in the last K days
Minimum price in the last K days
Dynamic price input through an interactive menu

This project is great for learning Stacks, Queues, Deques, Sliding Window techniques, and Algorithmic Thinking.

Features
1. Add Stock Prices

Dynamically input prices one by one during runtime.

2. Stock Span Calculation

Uses a stack-based O(n) algorithm to compute the span of each price.
(Span = consecutive days before today with stock price ≤ today’s price.)

3. Sliding Window Maximum (Last K Days)

Uses a deque to find the max efficiently in O(k) time.

4. Sliding Window Minimum (Last K Days)

Also uses deque for optimized performance.

5. Display All Entered Prices

Quickly review your dataset.

The core logic is inside the StockAnalyzer class, which maintains:

1. A vector<int> prices

2. A windowSize (K days)

3. Stack for stock span

4. Deque for sliding window max/min
