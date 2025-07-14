1. Cho một dãy số f(n) được định nghĩa như sau:
f(0) = 1
f(1) = 4
f(2) = 10
f(3) = 22
f(4) = 46
f(5) = 94
f(6) = 190
f(7) = 382
Hãy tìm mối liên hệ giữa các số tử đó viết hàm để tìm ra số f(n) hợp lệ (có thể có nhiều cách làm,
cần chỉ ra công thức tìm được)

2. Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

 

Example 1:

Input: k = 5

Output: "b"

Explanation:

Initially, word = "a". We need to do the operation three times:

Generated string is "b", word becomes "ab".
Generated string is "bc", word becomes "abbc".
Generated string is "bccd", word becomes "abbcbccd".

3. Cho mảng [1, 2, 6, 8, 35, 9]
Hãy in ra tất cả các tổ hợp các phần tử trong a[] sao cho tổng của chúng bằng đúng k.
Mỗi phần tử có thể sử dụng nhiều lần


4. Cho danh sách n hoạt động, mỗi hoạt động có thời điểm bắt đầu start[i] và kết thúc end[i].
Hãy chọn nhiều nhất số lượng hoạt động sao cho không có hai hoạt động nào trùng nhau về thời gian

| Hoạt động | Bắt đầu | Kết thúc |
| --------- | ------- | -------- |
| 1         | 1       | 3        |
| 2         | 2       | 5        |
| 3         | 4       | 7        |
| 4         | 1       | 8        |
| 5         | 5       | 9        |
| 6         | 8       | 10       |

5. Bạn có một thanh sắt dài n = 8 đơn vị, và một bảng giá price[i] cho biết giá bán của đoạn sắt dài i như sau
Hãy xác định cách cắt thanh sắt để thu được tổng giá trị lớn nhất.
Bạn có thể cắt thành nhiều đoạn hoặc giữ nguyên, miễn sao tổng độ dài vẫn là n.

| Độ dài `i`     | 1 | 2 | 3 | 4 | 5  | 6  | 7  | 8  |
| -------------- | - | - | - | - | -- | -- | -- | -- |
| Giá `price[i]` | 1 | 5 | 8 | 9 | 10 | 17 | 17 | 20 |

5. 

* Các bạn có thể sử dụng bất kỳ ngôn ngữ lập trình nào để cài đặt. Sau khi làm xong sẽ đẩy code lên github và nộp lại bài làm vào nhóm Zalo theo dạng 
Họ Và Tên - Link GitHub