/* FUN_80163248
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163248  body 0x80163248..0x801633f3  size 428 B
 * body sha256 ee11fddfa466a3436c654dcb42655979cc313092e7ee6c4d1162115ad88eab12
 * provider record sha256 2817780e36ea581b23ad0fdb6d14300d1df279dca3e508559ed01a6002b27a69
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163248(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = *(byte *)((int)param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if ((bVar1 == 2) && (iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100), iVar2 != 0)) {
        *(undefined1 *)((int)param_1 + 5) = 2;
        *(undefined2 *)((int)param_1 + 6) = 0;
        uVar3 = func_0x80033604();
        *(undefined *)((int)param_1 + 0x2b9) = (&DAT_80166c80)[uVar3 & 7];
      }
      goto LAB_801633ac;
    }
    if (bVar1 != 0) goto LAB_801633ac;
    *(undefined1 *)((int)param_1 + 7) = 1;
    param_1[0x7a] = 0x16000f00;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) >> 2;
    *(undefined1 *)((int)param_1 + 0x2ba) = 0;
    *(undefined1 *)((int)param_1 + 699) = 4;
  }
  func_0x80032bd8(param_1,0x800,0);
  *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
  if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
    *(undefined1 *)((int)param_1 + 7) = 2;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0;
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    *param_1 = *param_1 & 0xefffffff | 0x4000000;
    func_0x80077d18(10,param_1);
  }
  if (*(byte *)((int)param_1 + 0x1e9) < 0x11) {
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  else {
    *(undefined2 *)(param_1 + 0x78) = 0;
  }
LAB_801633ac:
  if (*(short *)(param_1 + 0x7d) < 0x800) {
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x80;
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 0x80;
  }
  return;
}
