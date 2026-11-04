/* FUN_8009bf04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009bf04  body 0x8009bf04..0x8009c0c3  size 448 B
 * body sha256 4f99811db3d067e138950f420cabb15510b69879f0a256f01dfc239d889908c7
 * provider record sha256 c25e0a294b3bea8571f0ab7d0c11136ef8ee7378d0ccd286ad157ded0b9d64fb
 * callees 6 direct (5 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8009bf04(int *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_40 [2];
  undefined1 local_3e;
  undefined *local_3c;
  int *local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  FUN_8009c1e0(&DAT_8013215c);
  uVar1 = func_0x8000cd40(1);
  func_0x80007320(param_1,0x8000);
  func_0x8000cd40(uVar1);
  local_3e = 0;
  local_3c = &DAT_80132140;
  local_34 = 0x8000000;
  local_30 = 0x8000;
  local_38 = param_1;
  func_0x80006f60(&DAT_8013215c,auStack_40,0);
  osRecvMesg(&DAT_80132140,&DAT_80132158,1);
  if (*param_1 == 0x42494f32) {
    uVar1 = 0;
  }
  else {
    func_0x80006650(param_1,0x8000);
    *param_1 = 0x42494f32;
    uVar1 = func_0x8000cd40(1);
    func_0x80007320(param_1,0x8000);
    func_0x8000cd40(uVar1);
    local_3e = 0;
    local_3c = &DAT_80132140;
    local_34 = 0x8000000;
    local_30 = 0x8000;
    local_38 = param_1;
    func_0x80006f60(&DAT_8013215c,auStack_40,1);
    osRecvMesg(&DAT_80132140,&DAT_80132158,1);
    func_0x80006650(param_1,0x8000);
    uVar1 = func_0x8000cd40(1);
    func_0x80007320(param_1,0x8000);
    func_0x8000cd40(uVar1);
    local_3e = 0;
    local_3c = &DAT_80132140;
    local_34 = 0x8000000;
    local_30 = 0x8000;
    local_38 = param_1;
    func_0x80006f60(&DAT_8013215c,auStack_40,0);
    osRecvMesg(&DAT_80132140,&DAT_80132158,1);
    uVar1 = 0xfffffffe;
    if (*param_1 == 0x42494f32) {
      uVar1 = 1;
    }
  }
  return uVar1;
}
