/* FUN_800961dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800961dc  body 0x800961dc..0x800962fb  size 288 B
 * body sha256 480467a8d6989021127876c5ff59ba6d8f6544c66d00a7796006b24bc459a01f
 * provider record sha256 630e738699ef1ed6d31924ff998bf93560b44ee0c011a866056e8811f620646a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800961dc(void)

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
  iVar5 = 3;
  puVar4 = (undefined2 *)(uVar1 + 0xa0a);
  puVar2 = &DAT_80131108;
  iVar3 = uVar1 + 0xa00;
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
  DAT_8012bfa6 = 0;
  DAT_8012bfc1 = 0;
  DAT_8012bfc0 = 0x32;
  DAT_8012bfb5 = 0;
  DAT_8012bfb4 = 0;
  DAT_8012bfb7 = 0;
  DAT_8012bfb6 = 0;
  return;
}
