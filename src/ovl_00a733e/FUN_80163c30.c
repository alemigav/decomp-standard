/* FUN_80163c30
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163c30  body 0x80163c30..0x80163d9b  size 364 B
 * body sha256 c005ba931f40c88d7d16d6db315e6b4f11839b69b4d4074889b618979ca3301b
 * provider record sha256 0baa646e7d39b5082476c041431e89a051eb7a6a6fd79876dbb2549ac7091d02
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163c30(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 == 1) {
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      *(undefined1 *)(param_1 + 7) = 2;
      *(undefined2 *)(param_1 + 500) = 0x1f;
      *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
      func_0x80089d54(param_1,param_2,param_3,0x40);
    }
    func_0x80032b5c(param_1,0);
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      *(undefined1 *)(param_1 + 7) = 1;
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x100);
      func_0x80077d18(0xb,param_1);
    }
  }
  else if (bVar1 == 2) {
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar2 = *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = sVar2 + -1;
    if (sVar2 == 1) {
      *(undefined1 *)(param_1 + 5) = 2;
      *(undefined2 *)(param_1 + 6) = 0;
      *(undefined1 *)(param_1 + 0x2b4) = 0;
      *(undefined1 *)(param_1 + 0x2b8) = 0x3c;
      FUN_80163824();
    }
  }
  return;
}
