#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class StockAnalyzer {
    vector<int> prices;   
    int windowSize;    

public:
    StockAnalyzer(int k) : windowSize(k) {}

    void addPrice(int price) {
        prices.push_back(price);
    }

    vector<int> getStockSpan() {
        vector<int> span(prices.size());
        stack<int> st;

        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] <= prices[i]){
                st.pop();
            }
            span[i] = (st.empty()) ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return span;
    }

    int getMaxInLastK() {
        if (prices.size() < windowSize) return -1;

        deque<int> dq;
        int n = prices.size();
        for (int i = n - windowSize; i < n; i++) {
            while (!dq.empty() && prices[dq.back()] <= prices[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return prices[dq.front()];
    }

    int getMinInLastK() {
        if (prices.size() < windowSize) return -1;

        deque<int> dq;
        int n = prices.size();
        for (int i = n - windowSize; i < n; i++) {
            while (!dq.empty() && prices[dq.back()] >= prices[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return prices[dq.front()];
    }

    void displayPrices() {
        cout << "Stock Prices: ";
        for (int p : prices){
            cout << p << " ";
        }
        cout << "\n";
    }
};

int main() {
    int k;
    cout << "Enter sliding window size (k days): ";
    cin >> k;

    StockAnalyzer analyzer(k);

    while (true) {
        cout << "\n---- Real-Time Stock Span Analyzer ----\n";
        cout << "1. Add Stock Price\n";
        cout << "2. Display Stock Prices\n";
        cout << "3. Show Stock Spans\n";
        cout << "4. Show Max in Last K Days\n";
        cout << "5. Show Min in Last K Days\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        int choice, price;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter stock price: ";
                cin >> price;
                analyzer.addPrice(price);
                break;

            case 2:
                analyzer.displayPrices();
                break;

            case 3: {
                vector<int> span = analyzer.getStockSpan();
                cout << "Stock Spans: ";
                for (int s : span) cout << s << " ";
                cout << "\n";
                break;
            }

            case 4:
                cout << "Max in last " << k << " days: " << analyzer.getMaxInLastK() << "\n";
                break;

            case 5:
                cout << "Min in last " << k << " days: " << analyzer.getMinInLastK() << "\n";
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
