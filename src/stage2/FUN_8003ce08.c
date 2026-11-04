/* FUN_8003ce08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ce08  body 0x8003ce08..0x8003cea7  size 160 B
 * body sha256 4f8896737675030dce1f8b9f35934953039722a8c060a1f9a5d539b50a02e56e
 * provider record sha256 8c88a071cf6a8f5420623935ca0b7d33033e7ad3c9a893c7fc30377502091186
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ce08(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar2 = DAT_800ebb94;
  local_20 = 0xfb500000;
  local_1c = 0x258012c;
  local_18 = 0xfda80000;
  local_14 = 0x12c0096;
  local_30 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_2c = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_28 = (int)*(short *)(DAT_800ebb94 + 0x38);
  switch(*(undefined2 *)(DAT_800ebb94 + 0x12)) {
  case 0:
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 1;
    *(undefined2 *)(puVar2 + 0x18) = 0x8403;
    *puVar2 = 0;
    DAT_800ebb94[1] = 0x31;
    FUN_80077adc(0x1130001,&local_30);
    if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x80) == 0) {
      puVar5 = &local_20;
    }
    else {
      puVar5 = &local_18;
    }
    FUN_800609e0(&local_30,(int)*(short *)(DAT_800ebb94 + 0x22),puVar5,0x1002000b);
    local_2c = local_2c + 0x708;
    FUN_800609e0(&local_30,(int)*(short *)(DAT_800ebb94 + 0x22),puVar5,0x1002000b);
    puVar2 = DAT_800ebb94;
    if (DAT_800ebb94[0xb] == -1) {
      *(undefined2 *)(DAT_800ebb94 + 0xe) = 0xf0;
      puVar2[8] = 0;
      puVar3 = DAT_800ebb94;
      *(undefined2 *)(puVar2 + 0xc) = 0;
      *(short *)(puVar2 + 0x36) = *(short *)(puVar2 + 0x36) + -0x1d6;
    }
    else {
      DAT_800ebb94[8] = 0xe9;
      puVar3 = DAT_800ebb94;
      *(undefined2 *)(puVar2 + 0xc) = 0;
      *(undefined2 *)(puVar2 + 0xe) = 0xf0;
    }
    puVar3[9] = 0;
    FUN_80038a20(0x30f2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
    FUN_80038a20(0x40c2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
    uVar4 = 0x41d1800;
    break;
  case 1:
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 2;
    if (puVar2[0xb] == -1) {
      *(short *)(puVar2 + 0x36) = *(short *)(puVar2 + 0x36) + -600;
    }
    FUN_80038a20(0x31f2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
    if (DAT_800ebb94[0xb] == -1) {
      *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -0x1d6;
      return;
    }
    return;
  case 2:
    pcVar1 = DAT_800ebb94 + 0xb;
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 3;
    if (*pcVar1 == -1) {
      *(short *)(puVar2 + 0x36) = *(short *)(puVar2 + 0x36) + -600;
    }
    uVar4 = 0x3142000;
    break;
  case 3:
    pcVar1 = DAT_800ebb94 + 0xb;
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 4;
    if (*pcVar1 == -1) {
      *(short *)(puVar2 + 0x36) = *(short *)(puVar2 + 0x36) + -600;
    }
    uVar4 = 0x40d2800;
    break;
  case 4:
    if (DAT_800ebb94[0xb] == -1) {
      *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -600;
    }
    FUN_80038a20(0x30f2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
    puVar2 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar2 = 0;
    *(undefined2 *)(puVar2 + 0x18) = 0;
  default:
    goto switchD_8003cea0_default;
  }
  FUN_80038a20(uVar4,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
switchD_8003cea0_default:
  return;
}
