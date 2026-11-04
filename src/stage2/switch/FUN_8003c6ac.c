/* FUN_8003c6ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c6ac  body 0x8003c6ac..0x8003c827  size 380 B
 * body sha256 b8061a202a71029cb14bf1d88e58e8cdc72c75d4d831cacaf170a66fdafad9d0
 * provider record sha256 4b1b98ce80a13639ce37c2ceab7c40df190b144c69f1830eb08ec96f8195ec77
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003c6a4::caseD_0(void)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack00000010;
  int iStack00000014;
  int iStack00000018;
  undefined1 auStack_40 [64];
  
  puVar2 = DAT_800ebb94;
  uStack00000010 = (int)*(short *)(DAT_800ebb94 + 0x34);
  bVar1 = DAT_800ebb94[0x1e];
  iStack00000014 = (int)*(short *)(DAT_800ebb94 + 0x36);
  iStack00000018 = (int)*(short *)(DAT_800ebb94 + 0x38);
  *(undefined2 *)(DAT_800ebb94 + 0x18) = 0x8400;
  *puVar2 = 0;
  DAT_800ebb94[1] = 0x2f;
  if (DAT_800ebb94[0x1e] == '\f') {
    FUN_80077adc(0x1110001,&uStack00000010);
    FUN_800609e0(&uStack00000010,(int)*(short *)(DAT_800ebb94 + 0x22),
                 auStack_40 + (uint)(byte)DAT_800ebb94[0x1e] * 8,0x10020009);
    iStack00000014 = iStack00000014 + 900;
    FUN_800609e0(&uStack00000010,(int)*(short *)(DAT_800ebb94 + 0x22),
                 auStack_40 + (uint)(byte)DAT_800ebb94[0x1e] * 8,0x10020009);
  }
  else {
    FUN_80077adc(0x1140001,&uStack00000010);
  }
  uVar3 = (bVar1 - 0xc) * 0xa00 & 0xffff;
  if (DAT_800ebb94[0xb] == -1) {
    *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -0x1d6;
  }
  uVar4 = uVar3 + 0x1700;
  FUN_80038a20(uVar4 | 0x31f0000,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
  FUN_80038a20(uVar3 + 0x1f00 | 0x40c0000,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
  FUN_80038a20(uVar4 | 0x41d0000,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
  *(undefined2 *)(DAT_800ebb94 + 0x12) = 1;
  return;
}
