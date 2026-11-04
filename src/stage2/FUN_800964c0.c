/* FUN_800964c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800964c0  body 0x800964c0..0x800965e3  size 292 B
 * body sha256 47f757d3e7f2313c2cba1956ff4c2b8d1a8f65f00e4b4e39d5ce7bd56ddf2c96
 * provider record sha256 25aff3112df15a9f112d1498863d42ea3b07c9fd8ee0209a699fa6f4eb096dff
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800964c0(void)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  
  uVar1 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar1 = DAT_800c52dc + 0x3c004U;
  }
  iVar5 = 2;
  puVar4 = (undefined2 *)(uVar1 + 0xa46);
  puVar2 = &UNK_80131134;
  iVar3 = uVar1 + 0xa3c;
  do {
    iVar5 = iVar5 + -1;
    FUN_80047b04(iVar3,0);
    FUN_8004786c(iVar3,0x80,0x80,0x80);
    FUN_800478ac(iVar3,puVar2[-4],puVar2[-3]);
    FUN_800479bc(iVar3,puVar2[-2],puVar2[-1]);
    *(undefined **)(puVar4 + 1) = &DAT_8012f584;
    *puVar4 = 0x20;
    puVar4 = puVar4 + 10;
    puVar2 = puVar2 + -4;
    iVar3 = iVar3 + 0x14;
  } while (iVar5 != 0);
  DAT_8012bfc3 = 0;
  DAT_8012bfc2 = 0x50;
  DAT_8012bfb9 = 0;
  DAT_8012bfb8 = 0;
  DAT_8012bfbb = 0;
  DAT_8012bfba = 0;
  DAT_8012bfa7 = DAT_8012bfa6;
  return;
}
