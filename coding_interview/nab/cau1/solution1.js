// Helper function để lấy chữ số đầu
function getFirstDigit(num) {
  while (num >= 10) {
      num = Math.floor(num / 10);
  }
  return num;
}

function solution(numbers) {
    // Hashmap để lưu chữ số đầu và cuối
    const firstDigitMap = {}; // Key: chữ số đầu, Value: số lần xuất hiện
    const lastDigitMap = {};  // Key: chữ số cuối, Value: số lần xuất hiện


    // Duyệt qua từng số để cập nhật hashmap
    numbers.forEach(num => {
        const firstDigit = getFirstDigit(num);
        const lastDigit = num % 10;

        // Cập nhật tần suất chữ số đầu
        firstDigitMap[firstDigit] = (firstDigitMap[firstDigit] || 0) + 1;
        // Cập nhật tần suất chữ số cuối
        lastDigitMap[lastDigit] = (lastDigitMap[lastDigit] || 0) + 1;
    });

    // Tính tổng số cặp
    let totalPairs = 0;
    numbers.forEach(num => {
        const firstDigit = getFirstDigit(num);
        const lastDigit = num % 10;

        // Tìm số lượng cặp dựa trên hashmap
        if (lastDigit in firstDigitMap) {
            totalPairs += firstDigitMap[lastDigit];
        }

        // Trừ đi trường hợp cặp (n, n) không hợp lệ
        if (getFirstDigit(num) === num % 10) {
            totalPairs--;
        }
    });

    return totalPairs;
}

console.log(solution([30, 12, 29, 91])); // Output: 
console.log(solution([122, 21, 21, 23])); // Output: 