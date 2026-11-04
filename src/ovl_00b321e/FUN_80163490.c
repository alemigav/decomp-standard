/* FUN_80163490
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163490  body 0x80163490..0x8016356f  size 224 B
 * body sha256 359ad916973baef8e0abaeef18a0b56fdc1cdc5a76a6e3e78965204e10a0da48
 * provider record sha256 514a5863788762f885f795f42f636b3eb02c0c36a4949aafc3012c6f4819752b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163490(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    param_1[0x7a] = 0x5000f00;
    FUN_801665a0();
    *(undefined1 *)((int)param_1 + 0x2c5) = 1;
    *(undefined2 *)(param_1 + 0x19) = 0;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined2 *)((int)param_1 + 6) = 0x100;
    *param_1 = *param_1 | 4;
    FUN_801665a0(param_1,1);
    *(undefined2 *)(param_1 + 0x78) = 0x30f;
    func_0x80032b5c(param_1,0);
    param_1[0x7a] = 0x8000000;
    *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + -0x400;
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  return;
}
