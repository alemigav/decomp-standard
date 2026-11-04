/* FUN_8009c0c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009c0c4  body 0x8009c0c4..0x8009c1df  size 284 B
 * body sha256 7cd91740863b9cde31b0023372561dc352a27c132bcfa55b47144fc1b9882d74
 * provider record sha256 c9856217277dfd56bbb1205269198a65a26df16a5a747f5f9cc2fd0b0f9b0339
 * callees 5 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8009c0c4(int *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_38 [2];
  undefined1 local_36;
  undefined *local_34;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  *param_1 = 0x42494f32;
  FUN_8009c1e0(&DAT_8013215c);
  uVar1 = func_0x8000cd40(1);
  func_0x80007320(param_1,0x8000);
  func_0x8000cd40(uVar1);
  local_36 = 0;
  local_34 = &DAT_80132140;
  local_2c = 0x8000000;
  local_28 = 0x8000;
  local_30 = param_1;
  func_0x80006f60(&DAT_8013215c,auStack_38,1);
  osRecvMesg(&DAT_80132140,&DAT_80132158,1);
  local_36 = 0;
  local_34 = &DAT_80132140;
  local_2c = 0x8000000;
  local_28 = 0x8000;
  local_30 = param_1;
  func_0x80006f60(&DAT_8013215c,auStack_38,0);
  osRecvMesg(&DAT_80132140,&DAT_80132158,1);
  uVar1 = 0xfffffffe;
  if (*param_1 == 0x42494f32) {
    uVar1 = 0;
  }
  return uVar1;
}
