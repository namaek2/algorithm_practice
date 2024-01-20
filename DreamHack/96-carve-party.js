//개발자 콘솔에 다음 스크립트 입력
for (var j = 0; j < 100; j += 1){
  for (var i = 0; i < pumpkin.length; i++) {
        pumpkin[i] ^= pie;
        pie = ((pie ^ 0xff) + (i * 10)) & 0xff;
      }
}
//그 다음 콘솔에서 카운터 변수 조작
counter = 10002;

//그 다음 호박 클릭

