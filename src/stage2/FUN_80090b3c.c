/* FUN_80090b3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090b3c  body 0x80090b3c..0x80090c9f  size 356 B
 * body sha256 152225db782bd8caea400fface9ba060c425ecc38a8a854fd8b4827d83fb9e17
 * provider record sha256 58d62ec2428890ae72f6023e3a65e2cd8e64b27f55b0b0bcd7d0f29b418ffe42
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80090b3c(void)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  FUN_800479c8(DAT_800c52dc + 0x4d007U & 0xfffffff8,&DAT_8012fa54,0x15c3,1);
  uVar1 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar1 = DAT_800c52dc + 0x3c004U;
  }
  iVar2 = uVar1 + 0xa64;
  iVar6 = 0xe;
  puVar3 = &DAT_8012fa08;
  do {
    iVar6 = iVar6 + -1;
    iVar5 = 2;
    puVar4 = (undefined1 *)(iVar2 + 3);
    do {
      FUN_80047b04(iVar2,0);
      FUN_8004786c(iVar2,0x80,0x80,0x80);
      if (puVar3[3] == '\0') {
        uVar1 = ((byte)puVar3[2] & 3) << 3 | 0x20;
      }
      else {
        uVar1 = ((byte)puVar3[2] & 3) << 3;
      }
      iVar5 = iVar5 + -1;
      FUN_800478ac(iVar2,uVar1,0);
      FUN_800478b8(iVar2,*(undefined2 *)(puVar3 + 4),*(undefined2 *)(puVar3 + 6));
      FUN_800479bc(iVar2,8,8);
      *(undefined **)(puVar4 + 9) = &DAT_8012fa54;
      *(undefined2 *)(puVar4 + 7) = 0;
      *puVar4 = 0;
      puVar4 = puVar4 + 0x14;
      iVar2 = iVar2 + 0x14;
    } while (iVar5 != 0);
    puVar3 = puVar3 + -8;
  } while (iVar6 != 0);
  return;
}
