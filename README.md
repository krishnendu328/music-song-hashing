# Music Song ID Hashing & Search Analysis

Assignment implementing Hash Tables (Division Method with Linear Probing) and Linear Search for a music application storing song IDs.

---

## 1. Input Data
The song IDs used for this assignment are:
* **105, 210, 315, 420, 525, 630, 735, 840**

---

## 2. Part A: Hash Table Insertion & Trace Table
* **Hash Function:** $h(k) = k \pmod m$
* **Table Size ($m$):** $10$
* **Collision Resolution:** Linear Probing ($h'(k, i) = (h(k) + i) \pmod m$)

| Insertion Step | Song ID ($k$) | Hash Index $h(k)$ | Collision? | Resolution / Final Index | Table State After Insertion |
| :--- | :---: | :---: | :---: | :---: | :--- |
| **1** | **105** | 5 | No | Index 5 | `[-, -, -, -, -, 105, -, -, -, -]` |
| **2** | **210** | 0 | No | Index 0 | `[210, -, -, -, -, 105, -, -, -, -]` |
| **3** | **315** | 5 | **Yes** | Probe to Index 6 | `[210, -, -, -, -, 105, 315, -, -, -]` |
| **4** | **420** | 0 | **Yes** | Probe to Index 1 | `[210, 420, -, -, -, 105, 315, -, -, -]` |
| **5** | **525** | 5 | **Yes** | Probe to Index 7 | `[210, 420, -, -, -, 105, 315, 525, -, -]` |
| **6** | **630** | 0 | **Yes** | Probe to Index 2 | `[210, 420, 630, -, -, 105, 315, 525, -, -]` |
| **7** | **735** | 5 | **Yes** | Probe to Index 8 | `[210, 420, 630, -, -, 105, 315, 525, 735, -]` |
| **8** | **840** | 0 | **Yes** | Probe to Index 3 | `[210, 420, 630, 840, -, 105, 315, 525, 735, -]` |

---

## 3. Part B: Search Comparisons
Searching for sample IDs:

| Search ID | Hashing Operations / Comparisons | Linear Search Operations / Comparisons |
| :--- | :--- | :--- |
| **315** | **2 comparisons** (Index 5 $\rightarrow$ Index 6) | **3 comparisons** (Scanned 105, 210, 315) |
| **840** | **4 comparisons** (Index 0 $\rightarrow$ 1 $\rightarrow$ 2 $\rightarrow$ 3) | **8 comparisons** (Scanned entire dataset) |

---

## 4. Part C: Performance Analysis & Conclusion

### A. Load Factor ($\alpha$) Calculation
$$\alpha = \frac{\text{Number of Stored Keys } (N)}{\text{Size of Hash Table } (m)} = \frac{8}{10} = 0.8 \text{ (or 80\%)}$$

### B. Time & Space Complexity Analysis
* **Hashing (Linear Probing):**
  * **Average Time Complexity:** $O(1)$ under a low load factor.
  * **Worst-Case Time Complexity:** $O(N)$ when primary clustering occurs.
  * **Space Complexity:** $O(m)$ for the hash table array.
* **Linear Search:**
  * **Time Complexity (Best/Average/Worst):** $O(N)$ because it requires sequentially scanning elements.
  * **Space Complexity:** $O(1)$ extra space (in-place search).

### C. Comparison Table
| Metric | Hashing (with Linear Probing) | Linear Search |
| :--- | :--- | :--- |
| **Search Performance** | Faster ($O(1)$ to $O(N)$) | Slower ($O(N)$) |
| **Clustering Impact** | Affected by primary clustering due to patterns in song IDs. | Unaffected by clustering or key distribution. |
| **Extra Storage** | Requires pre-allocated table space ($O(m)$). | Requires minimal/no extra space ($O(1)$). |

### D. Final Conclusion
1. **Effect of Collisions:** Because all given song IDs are multiples of 105, they map exclusively to indices `0` and `5`. This caused severe **primary clustering** under linear probing, increasing probe lengths and operations for subsequent insertions and searches.
2. **Suitability:** Hashing is fundamentally the most suitable approach for a music application because lookups need to be extremely fast. However, to eliminate clustering caused by patterned keys, a **prime table size** (e.g., $m = 11$) or an alternative collision resolution strategy (such as **Chaining** or **Quadratic Probing**) should be implemented in production.