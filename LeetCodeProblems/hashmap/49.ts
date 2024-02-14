function groupAnagrams(strs: string[]): string[][] {
      const answer: string[][] = [];
  let anagramIndex: number = 0;
  const mapOfStrings: object = {};
  for(let i = 0; i < strs.length; i++) {
    const originalString = strs[i];
    const str: string = strs[i].split("").sort().join("");
    if (!mapOfStrings[str] && mapOfStrings[str] != 0) {
      mapOfStrings[str] = anagramIndex;
      answer.push([]);
      answer[anagramIndex].push(originalString);
      anagramIndex++;
      continue;
    }
    if (mapOfStrings[str] != null) {
      answer[mapOfStrings[str]].push(originalString);
      continue;
    }
  }
  return answer; 
};