# binaryLoadBalance
A binary (with offset regulation) load balance. Sample:

./binaryLoadBalance 8 5000 1.2
1 range: \[0 - 3000\[                     (total of elements: 3000)
2 range: \[3000 - 4200\[                  (total of elements: 1200)
3 range: \[4200 - 4680\[                  (total of elements: 480)
4 range: \[4680 - 4872\[                  (total of elements: 192)
5 range: \[4872 - 4948\[                  (total of elements: 76)
6 range: \[4948 - 4979\[                  (total of elements: 31)
7 range: \[4979 - 4991\[                  (total of elements: 12)
8 range: \[4991 - 5000\[                  (total of elements: 9)

Grand total: 5000
