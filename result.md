# Results

```bash
[pavel@Station go]$ for i in {1..10}; do go run foo.go; done
The magic number is: -62907
The magic number is: -126590
The magic number is: -77821
The magic number is: -707020
The magic number is: -783520
The magic number is: 562581
The magic number is: -703919
The magic number is: 0
The magic number is: 473985
The magic number is: -9036
[pavel@Station go]$ for i in {1..10}; do ../c/foo ; done
The magic number is: -257395
The magic number is: 272226
The magic number is: 474873
The magic number is: 575799
The magic number is: 772754
The magic number is: -139913
The magic number is: -50608
The magic number is: -340532
The magic number is: -128029
The magic number is: 10512
[pavel@Station go]$ 
```

The results appears random because thread increment and thread decrement access and modifies the same variable out of order. I tried to fix it with a mutex lock however it for some reason didn't work either. Maybe I'll figure it out at some later point. 