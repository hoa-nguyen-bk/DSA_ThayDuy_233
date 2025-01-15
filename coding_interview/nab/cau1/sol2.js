function solution(D, X) {
  let days = 0;
  let start = 0;

  while (start < D.length) {

    let end = start;
    const firstMission = D[start];


    while (end < D.length && Math.abs(D[end] - firstMission) <= X) {
      end++;
    }


    days++;
    start = end;
  }

  return days;
}

function solution(D, X) {
  let days = 1;
  let firstMission = D[0];

  for (let i = 1; i < D.length; i++) {

    if (Math.abs(D[i] - firstMission) > X) {
      days++;
      firstMission = D[i];
    }
  }

  return days;
}

function solution(D, X) {
  let days = 1; 
  let minDifficulty = D[0]; 
  let maxDifficulty = D[0]; 

  for (let i = 1; i < D.length; i++) {
      
      minDifficulty = Math.min(minDifficulty, D[i]);
      maxDifficulty = Math.max(maxDifficulty, D[i]);

      
      if (maxDifficulty - minDifficulty > X) {
          days++;
          minDifficulty = D[i]; 
          maxDifficulty = D[i];
      }
  }

  return days;
}


console.log(solution([5, 8, 2, 7], 3)); // Output: 3
console.log(solution([2, 5, 9, 2, 1, 4], 4)); // Output: 3
console.log(solution([1, 12, 10, 4, 5, 2], 2)); // Output: 4