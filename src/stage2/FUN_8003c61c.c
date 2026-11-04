/* FUN_8003c61c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c61c  body 0x8003c61c..0x8003c6ab  size 144 B
 * body sha256 16cf5b3be28ecebb754c37ddabd6719080f2bcd059b52bcb5a7b8bebf388f4bf
 * provider record sha256 3f3fe622a5e0ace093b9024c6cbc353592c3bf92e89e782747829fe68397a0dd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c61c(void)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_88 [80];
  int iStack_38;
  int iStack_34;
  int iStack_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  puVar2 = DAT_800ebb94;
  local_28 = 0xf8300000;
  local_24 = 0x3e801f4;
  local_20 = 0xfc180000;
  local_1c = 0x1f400fa;
  switch(*(undefined2 *)(DAT_800ebb94 + 0x12)) {
  case 0:
    iStack_38 = (int)*(short *)(DAT_800ebb94 + 0x34);
    bVar1 = DAT_800ebb94[0x1e];
    iStack_34 = (int)*(short *)(DAT_800ebb94 + 0x36);
    iStack_30 = (int)*(short *)(DAT_800ebb94 + 0x38);
    *(undefined2 *)(DAT_800ebb94 + 0x18) = 0x8400;
    *puVar2 = 0;
    DAT_800ebb94[1] = 0x2f;
    if (DAT_800ebb94[0x1e] == '\f') {
      FUN_80077adc(0x1110001,&iStack_38);
      FUN_800609e0(&iStack_38,(int)*(short *)(DAT_800ebb94 + 0x22),
                   auStack_88 + (uint)(byte)DAT_800ebb94[0x1e] * 8,0x10020009);
      iStack_34 = iStack_34 + 900;
      FUN_800609e0(&iStack_38,(int)*(short *)(DAT_800ebb94 + 0x22),
                   auStack_88 + (uint)(byte)DAT_800ebb94[0x1e] * 8,0x10020009);
    }
    else {
      FUN_80077adc(0x1140001,&iStack_38);
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
    break;
  case 1:
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 2;
    break;
  case 2:
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 3;
    break;
  case 3:
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 4;
    break;
  case 4:
    if (DAT_800ebb94[0xb] == -1) {
      *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -600;
    }
    FUN_80038a20(0x4152700,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
    puVar2 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar2 = 0;
    *(undefined2 *)(puVar2 + 0x18) = 0;
  }
  return;
}
