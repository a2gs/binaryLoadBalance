# binaryLoadBalance
A binary (with offset regulation) load balance. Sample:<br><br>

./binaryLoadBalance 8 5000 1.2<br>
1 range: \[0 - 3000\[                     (total of elements: 3000)<br>
2 range: \[3000 - 4200\[                  (total of elements: 1200)<br>
3 range: \[4200 - 4680\[                  (total of elements: 480)<br>
4 range: \[4680 - 4872\[                  (total of elements: 192)<br>
5 range: \[4872 - 4948\[                  (total of elements: 76)<br>
6 range: \[4948 - 4979\[                  (total of elements: 31)<br>
7 range: \[4979 - 4991\[                  (total of elements: 12)<br>
8 range: \[4991 - 5000\[                  (total of elements: 9)<br><br>

Grand total: 5000<br>
