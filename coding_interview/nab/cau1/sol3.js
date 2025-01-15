function solution(A) {
  
  const sortedA = [...A].sort((a, b) => a - b);
  
  let slices = 0; 
  let currentMax = -Infinity; 

  
  for (let i = 0; i < A.length; i++) {
      currentMax = Math.max(currentMax, A[i]); 
      
      if (currentMax === sortedA[i]) {
          slices++;
      }
  }

  return slices;
}
