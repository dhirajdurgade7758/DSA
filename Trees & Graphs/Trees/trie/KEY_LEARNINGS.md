# KEY LEARNINGS FROM ALL TRIE PROBLEMS

## 1. FOUNDATIONAL CONCEPTS

### Trie Node Structure
```cpp
class Node {
    unordered_map<char, Node*> children;  // Character branches
    bool endOfWord;                        // Marks complete word
    int frequency;                         // Optional: track occurrences
};
```

### Core Principle
- **Trie = Prefix Tree**: Share common prefixes, diverge on differences
- Each path from root to endOfWord node represents ONE complete word
- Paths don't need endOfWord = true represent valid PREFIXES only

---

## 2. CRITICAL DISTINCTION: endOfWord vs Prefix

### endOfWord Matters
- `search()`: Returns true only at endOfWord=true nodes
- `longestCommonPrefix()`: STOPS when endOfWord=true (divergence point)
- `wordBreak()`: Only segments using complete words (endOfWord=true)
- `longestWordWithAllPrefixes()`: All intermediate steps must have endOfWord=true

### endOfWord NOT Required  
- `startsWith()`: Just checks if path exists (any node is valid)
- `searchWithWildcard()`: Finds patterns regardless of word completion
- `wordSearch2D()`: Finds words in spatial paths without prefix validation

**Key**: Think about whether you need complete words or just partial paths.

---

## 3. CORE OPERATIONS & PATTERNS

### Pattern 1: Simple Insert & Search
**Used In**: Building Trie, Searching, Implement Trie (LeetCode 208)
```
Insert: Create nodes as needed, mark last as endOfWord
Search: Follow path, check endOfWord at end
```
⏱️ **Time**: O(m) where m = word length  
💾 **Space**: O(n*m) for Trie storage

---

### Pattern 2: Frequency/Count Tracking
**Used In**: Prefix Problem (Unique Prefixes), Count Unique Substrings
- Add `int frequency` to each node
- Increment frequency when passing through during insert
- **Key Insight**: Each NEW node created = new unique substring/prefix
- Stop at first node where frequency=1 (unique point)

```cpp
// Unique prefixes: Stop at freq=1
while (temp->children.size() == 1 && temp->frequency > 1) {
    // Continues only if still shared with other words
}

// Unique substrings: Count every NEW node
int nodeCount = 0;  // Each new node = new substring
```

⏱️ **Time**: O(n²) for substrings (n = string length)  
💾 **Space**: O(n²) worst case

---

### Pattern 3: Branching Detection
**Used In**: Longest Common Prefix
- Traverse until: `children.size() != 1` OR `endOfWord = true`
- First divergence point = end of common prefix
- Branch = different paths for different characters

```cpp
while (children.size() == 1 && !endOfWord) {
    // Single path forward
    temp = temp->children[only_char];
    path += only_char;
}
```

⏱️ **Time**: O(m) where m = shortest string length  
💾 **Space**: O(m) for result string

---

### Pattern 4: Wildcard Matching (DFS + Backtracking)
**Used In**: Design Add/Search Words (LeetCode 211)
- '.' matches ANY single character → try all 26 branches
- Regular char → follow specific branch
- Use recursion with backtracking for each wildcard

```cpp
bool search(string& word, int idx, Node* node) {
    if (idx == word.size()) {
        return node->endOfWord;
    }
    
    if (word[idx] == '.') {
        // Try ALL children
        for (auto& [ch, child] : node->children) {
            if (search(word, idx + 1, child)) return true;
        }
        return false;
    } else {
        // Follow specific character
        if (!node->children.count(word[idx])) return false;
        return search(word, idx + 1, node->children[word[idx]]);
    }
}
```

⏱️ **Time**: O(n × 26^m) worst case (m = wildcards)  
💾 **Space**: O(m) recursion depth

---

### Pattern 5: 2D Spatial Traversal (Grid + Trie)
**Used In**: Word Search II (LeetCode 212)
- Simultaneously traverse 2D board AND Trie
- Mark visited cells with '#' (not Trie node marking)
- CRITICAL: Restore cell after DFS (backtracking)

```cpp
void dfs(board, trie_node, result, i, j) {
    // Boundary + visited check
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') return;
    
    char ch = board[i][j];
    if (!trie_node->children.count(ch)) return;  // Not in Trie
    
    trie_node = trie_node->children[ch];
    
    if (trie_node->endOfWord) {
        result.add(word);  // Found!
        trie_node->endOfWord = false;  // Avoid duplicates
    }
    
    board[i][j] = '#';  // Mark as visited
    dfs(board, trie_node, result, i+1, j);  // 4 directions
    dfs(board, trie_node, result, i-1, j);
    dfs(board, trie_node, result, i, j+1);
    dfs(board, trie_node, result, i, j-1);
    board[i][j] = ch;  // Restore (backtrack)
}
```

⏱️ **Time**: O(N × 4^L) where N = cells, L = max word length  
💾 **Space**: O(T + L) Trie + recursion depth

**Key Challenges**:
- ✓ Boundary checking for 2D grid
- ✓ Proper cell restoration (backtracking)
- ✓ Avoid duplicate results (mark endOfWord=false after finding)
- ✓ Trie pruning optimization (remove nodes after use)

---

### Pattern 6: Sorted Key Grouping
**Used In**: Group Anagrams (LeetCode 49)
- Sort characters of word → anagrams have identical sorted form
- Use sorted string as Trie insertion path
- All anagrams converge to SAME Trie node
- Collect originals at that node

```cpp
string sorted_key = word;
sort(sorted_key.begin(), sorted_key.end());
// Insert sorted_key into Trie (not original word)
// Store original word at final node
```

⏱️ **Time**: O(n × m log m) for sorting all words  
💾 **Space**: O(n × m) Trie storage

---

### Pattern 7: Suffix-based Counting
**Used In**: Count Unique Substrings
- Generate all suffixes: s[0:], s[1:], s[2:], ...
- Insert each suffix into Trie
- **Every NEW node = new unique substring**
- Count = number of nodes created (each node = unique substring)

```cpp
// For "abc": suffixes are "abc", "bc", "c"
for (int i = 0; i < n; i++) {
    insert(s.substr(i));  // Insert suffix starting at i
    // Each new node created increments count
}
// Total substrings = count + 1 (for empty string)
```

⏱️ **Time**: O(n²)  
💾 **Space**: O(n²)  
✓ **Insight**: Number of unique substrings = nodes created while building

---

### Pattern 8: Recursive Segmentation with Memoization
**Used In**: Word Break (LeetCode 139)
- Try every split position: does first part exist in Trie?
- If yes, recursively check remaining part
- **Optimize with memoization** to avoid exponential recalculation

```cpp
// Without memoization: O(2^n) exponential
bool canBreak(string s, Trie& trie) {
    if (s.empty()) return true;
    for (int i = 1; i <= s.size(); i++) {
        if (trie.search(s.substr(0, i)) && canBreak(s.substr(i), trie)) {
            return true;
        }
    }
    return false;
}

// With memoization: O(n²)
unordered_map<string, bool> memo;
bool canBreakMemo(string s, Trie& trie, map& memo) {
    if (memo.count(s)) return memo[s];  // Check cache
    if (s.empty()) return true;
    
    for (int i = 1; i <= s.size(); i++) {
        if (trie.search(s.substr(0, i)) && canBreakMemo(s.substr(i), trie, memo)) {
            return memo[s] = true;  // Store and return
        }
    }
    return memo[s] = false;
}
```

⏱️ **Time**: O(2^n) → O(n²) with memoization  
💾 **Space**: O(n) or O(n²) with memo

---

### Pattern 9: All-Prefix Validation (Strict Traversal)
**Used In**: Longest Word With All Prefixes (LeetCode 1858)
- Only continue DFS if current node is endOfWord=true
- This ensures every prefix is a valid complete word
- Track longest valid word found

```cpp
string dfs(Node* node) {
    if (!node->endOfWord) return "";  // Stop if not complete word
    
    string longest = (node->endOfWord ? current_word : "");
    
    for (auto& [ch, child] : node->children) {
        string result = dfs(child);
        if (result.length() > longest.length()) {
            longest = result;
        }
    }
    return longest;
}
```

⏱️ **Time**: O(n × m) for Trie ops  
💾 **Space**: O(n × m) Trie storage

---

## 4. DECISION TREE: Which Pattern to Use?

```
Do you need COMPLETE WORDS?
├─ YES:
│  ├─ Check endOfWord = true at end
│  ├─ Examples: search, word break, word search 2D
│  └─ Pattern: Filter by endOfWord
│
├─ NO (just prefixes):
│  ├─ Any node in path is valid
│  ├─ Examples: startsWith, autocomplete
│  └─ Pattern: Just check path existence
│
Need MULTIPLE MATCHES?
├─ YES (all solutions):
│  ├─ DFS with collection
│  ├─ Examples: word search 2D, group anagrams
│  └─ Pattern: Find ALL endOfWord nodes
│
├─ NO (single answer):
│  ├─ Traverse 1 path, stop at condition
│  ├─ Examples: LCP, longest word with prefixes
│  └─ Pattern: Stop when condition met
│
Working with 2D GRID?
├─ YES:
│  ├─ Mark visited with '#', restore after
│  ├─ Check 4 directions (up, down, left, right)
│  └─ Pattern: 2D DFS + Backtracking
│
├─ NO (1D string):
│  ├─ Simple traversal or recursion
│  └─ Pattern: Linear traversal with recursion
│
Dealing with WILDCARDS or VARIABLES?
├─ YES:
│  ├─ Try ALL possible branches
│  ├─ Use DFS with each wildcard = 26 branches
│  └─ Pattern: Branch explosion (26^m)
│
├─ NO (fixed characters):
│  ├─ Follow specific paths only
│  └─ Pattern: Deterministic traversal
│
Need NEW NODE COUNTING?
├─ YES:
│  ├─ Frequency + node creation checking
│  ├─ Examples: unique substrings, unique prefixes
│  └─ Pattern: Count novel nodes
│
├─ NO (word existence):
│  ├─ Just endOfWord flags
│  └─ Pattern: Standard search
```

---

## 5. OPTIMIZATION TECHNIQUES

### Memoization
**Used In**: Word Break DP
- Cache results of subproblems
- Reduces O(2^n) to O(n²)
- Store as `unordered_map<string, bool>`

### Trie Pruning
**Used In**: Word Search II
- After finding a word, set `endOfWord = false`
- Optionally: remove node if no more children
- Reduces search space for remaining words

### Early Termination  
**Used In**: Longest Common Prefix, Longest Word with Prefixes
- Stop as soon as condition met
- Don't traverse entire Trie if answer found

### Sorted Key Transformation
**Used In**: Group Anagrams
- Sort word characters before insertion
- O(m log m) per word but enables grouping

---

## 6. COMMON PITFALLS & SOLUTIONS

| Pitfall | Problem | Solution |
|---------|---------|----------|
| Not marking visited cells | Word Search II | Mark with '#', restore after DFS |
| Duplicate results | Word Search II | Mark endOfWord=false after adding word |
| Missing endOfWord check | Searching | Return true only if endOfWord=true |
| Not stopping at branching | LCP | Stop when children.size() != 1 |
| Exponential time | Word Break | Use memoization for subproblems |
| No backtracking | Wildcard search | Restore state after recursive calls |
| Missing wildcard logic | Design Add/Search | Treat '.' as 26 possible characters |
| Over-counting substrings | Count Unique | Each NEW node = 1 unique substring |

---

## 7. COMPLEXITY PATTERNS

### Time Complexity Summary
| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| Insert/Search | O(m) | - | m = word length |
| All inserts | O(n×m) | - | n = words, m = avg length |
| Build & Search | O(n×m) | O(n×m) | Standard Trie operations |
| With DFS (grid) | O(N × 4^L) | O(T+L) | N = cells, L = max word len |
| With wildcards | O(n × 26^m) | O(m) | m = word length |
| With memoization | O(n²) | O(n²) | Reduces from exponential |
| Suffix counting | O(n²) | O(n²) | All suffixes + insertion |
| Frequency tracking | O(n×m) | O(n×m) | Just adds frequency field |

---

## 8. KEY INSIGHTS & PATTERNS

### 1. **Trie as Filter/Validator**
- Trie is excellent for quickly EXCLUDING invalid paths
- Word Search II: Skip branches not in Trie early
- Much faster than checking strings directly

### 2. **Node State Matters**
- `endOfWord`: Complete word marker (CRITICAL)
- `frequency`: How many words pass through (shared prefixes)
- `children.size()`: Branching point detector

### 3. **Backtracking is Essential**
- When exploring alternatives (DFS), restore state
- Critical for: wildcards, 2D grid, spatial searches
- Pattern: `modify → recurse → restore`

### 4. **Trie Convergence**
- Different paths can share prefixes → converge at nodes
- Group Anagrams: All anagrams converge
- Longest Word: Multiple valid prefixes might converge

### 5. **Early Stopping Conditions**
- LCP: Stop at first child count != 1
- Prefix: Stop at first frequency == 1
- Spatial: Stop at invalid path in Trie
- Pattern: Identify WHEN to stop before WHY

### 6. **Memoization Transforms Complexity**
- Word Break without memo: O(2^n) — exponential
- Word Break with memo: O(n²) — polynomial
- Always consider memoization for overlapping subproblems

---

## 9. PROBLEM DIFFICULTY PROGRESSION

### EASY (Foundation)
1. Building a Trie — understand node structure
2. Searching in Trie — basic traversal
3. Implement Trie (208) — standard operations
4. Unique Prefixes — add frequency tracking
5. Longest Common Prefix (14) — detect branching

**Skills**: Basic DFS, node creation, path following

### MEDIUM (Advanced Techniques)
1. Count Unique Substrings — suffix-based counting
2. Group Anagrams (49) — sorted key mapping
3. Longest Word with Prefixes (1858) — strict validation
4. Word Break (139) — segmentation with recursion
5. Word Break DP (139) — memoization optimization
6. Design Add/Search (211) — wildcard handling with DFS

**Skills**: DFS with backtracking, memoization, pattern matching

### HARD (Integration)
1. Word Search II (212) — 2D grid + Trie + backtracking

**Skills**: 2D traversal, visited tracking, restoration, optimization (Trie pruning)

---

## 10. STUDY ROADMAP

**Phase 1: Build Foundation**
- Understand Node structure (children + endOfWord)
- Practice insert, search, startsWith

**Phase 2: Recognize Patterns**
- Branching = divergence → stop at LCP
- Frequency = shared prefixes → find unique
- New nodes = unique substrings → count nodes

**Phase 3: Combine Techniques**
- Trie + DFS = Word Search II
- Trie + Memoization = Word Break DP
- Trie + Sorting = Group Anagrams

**Phase 4: Optimize**
- Pruning for performance
- Early termination
- Smart state management

---

## 11. QUICK REFERENCE

### When to use each Trie technique:

| Goal | Technique | Example |
|------|-----------|---------|
| Find common start | Stop at branching | Longest Common Prefix |
| Group similar | Sorted key mapping | Group Anagrams |
| Count unique | Node creation counter | Unique Substrings |
| Find all matches | DFS collection | Word Search II |
| Match patterns | Wildcard DFS | Design Add/Search |
| Segment string | Recursive splits + memo | Word Break |
| Find longest valid | Strict node validation | Longest Word (all prefixes) |
| Avoid recalculation | Memoization | Word Break DP |

