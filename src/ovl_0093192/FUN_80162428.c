/* FUN_80162428
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162428  body 0x80162428..0x80162553  size 300 B
 * body sha256 b15ce5f6faf60bb727426037c8deaa424e8912ee961ba2a60587824d07af0766
 * provider record sha256 ac42fd1712b6c51ca2035ee001a64381dd657e6451260f15fa41a5f44d3cc20d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162428(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  int iVar1;
  uint uVar2;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0x28;
    *(undefined1 *)((int)param_1 + 0x2be) = 1;
    *param_1 = *param_1 | 2;
  }
  func_0x80032bd8(param_1,0,0);
  sVar3 = *(short *)((int)param_1 + 0x1e2) + 0x28;
  if (799 < *(short *)((int)param_1 + 0x1e2)) {
    sVar3 = 800;
  }
  *(short *)((int)param_1 + 0x1e2) = sVar3;
  *(undefined1 *)((int)param_1 + 0x26f) = 0xff;
  iVar1 = FUN_80162c90(param_1);
  if (iVar1 != 0) {
    *(undefined1 *)((int)param_1 + 0x26f) = 0;
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    *param_1 = *param_1 & 0xfffffffd | 0x4000000;
    if (iVar1 < 0) {
      param_1[0xb] = iVar1 + 10;
      *(undefined1 *)((int)param_1 + 5) = 4;
      FUN_80162b9c(param_1,0,0x82);
      uVar2 = *param_1 | 0x400;
    }
    else {
      *(undefined1 *)((int)param_1 + 5) = 1;
      param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
      uVar2 = *param_1 & 0xfffffbff;
    }
    *param_1 = uVar2;
    *(undefined2 *)((int)param_1 + 6) = 0;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  return;
}
