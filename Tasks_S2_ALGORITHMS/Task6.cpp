#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

struct Product {
    std::string name;
    double price;
    double rating;
    int popularity;
};

// Helper function to print products
void printProducts(const std::vector<Product>& products) {
    for (const auto& product : products) {
        std::cout << product.name << " | Price: " << product.price
                  << " | Rating: " << product.rating
                  << " | Popularity: " << product.popularity << std::endl;
    }
}

// QuickSort Partition function
int partition(std::vector<Product>& products, int low, int high, std::string key) {
    Product pivot = products[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((key == "price" && products[j].price < pivot.price) ||
            (key == "rating" && products[j].rating > pivot.rating) || // Higher rating is better
            (key == "popularity" && products[j].popularity > pivot.popularity)) { // Higher popularity is better
            std::swap(products[++i], products[j]);
        }
    }
    std::swap(products[i + 1], products[high]);
    return i + 1;
}

void quickSort(std::vector<Product>& products, int low, int high, std::string key) {
    if (low < high) {
        int pi = partition(products, low, high, key);
        quickSort(products, low, pi - 1, key);
        quickSort(products, pi + 1, high, key);
    }
}

// Merge function for MergeSort
void merge(std::vector<Product>& products, int left, int mid, int right, std::string key) {
    int n1 = mid - left + 1, n2 = right - mid;
    std::vector<Product> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = products[left + i];
    for (int j = 0; j < n2; j++) R[j] = products[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((key == "price" && L[i].price <= R[j].price) ||
            (key == "rating" && L[i].rating >= R[j].rating) ||
            (key == "popularity" && L[i].popularity >= R[j].popularity)) {
            products[k++] = L[i++];
        } else {
            products[k++] = R[j++];
        }
    }
    while (i < n1) products[k++] = L[i++];
    while (j < n2) products[k++] = R[j++];
}

void mergeSort(std::vector<Product>& products, int left, int right, std::string key) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(products, left, mid, key);
        mergeSort(products, mid + 1, right, key);
        merge(products, left, mid, right, key);
    }
}

int main() {
    std::vector<Product> products = {
        {"Laptop", 999.99, 4.5, 300},
        {"Phone", 699.99, 4.8, 500},
        {"Headphones", 199.99, 4.3, 200},
        {"Monitor", 299.99, 4.7, 400},
        {"Mouse", 49.99, 4.2, 250}
    };

    std::vector<Product> quickSortProducts = products;
    std::vector<Product> mergeSortProducts = products;

    // QuickSort timing
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(quickSortProducts, 0, quickSortProducts.size() - 1, "price");
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "QuickSort (by price) Execution Time: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms" << std::endl;

    printProducts(quickSortProducts);

    // MergeSort timing
    start = std::chrono::high_resolution_clock::now();
    mergeSort(mergeSortProducts, 0, mergeSortProducts.size() - 1, "price");
    end = std::chrono::high_resolution_clock::now();
    std::cout << "MergeSort (by price) Execution Time: "
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms" << std::endl;

    printProducts(mergeSortProducts);

    return 0;
}
