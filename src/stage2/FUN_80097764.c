/* FUN_80097764
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097764  body 0x80097764..0x800978a3  size 320 B
 * body sha256 0c837a97b95da357f1a2ad1639c5e72ebdd319a25cda78d4a49cacd141801722
 * provider record sha256 4ff124123a980207ac97b0e03d94be00d130f33ed5f2d2b55ad22d210b5d2ad0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097764(void)

{
  uint uVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar1 = DAT_800c52dc + 0x3c004U;
  }
  iVar5 = 7;
  if (DAT_800e1138 < 0xe) {
    DAT_801313ad = 0x1e;
  }
  else {
    DAT_801313ad = 0x3c;
  }
  puVar3 = (undefined2 *)(uVar1 + 0x6d6);
  puVar2 = &UNK_801313c8;
  iVar4 = uVar1 + 0x6cc;
  do {
    iVar5 = iVar5 + -1;
    FUN_80047b04(iVar4,0);
    FUN_8004786c(iVar4,0x80,0x80,0x80);
    FUN_800478ac(iVar4,puVar2[-4],puVar2[-3]);
    FUN_800479bc(iVar4,puVar2[-2],puVar2[-1]);
    *(undefined **)(puVar3 + 1) = &DAT_8012f530;
    *puVar3 = 0;
    puVar3 = puVar3 + 10;
    puVar2 = puVar2 + -4;
    iVar4 = iVar4 + 0x14;
  } while (iVar5 != 0);
  DAT_8012bfcc = 0xdc;
  DAT_8012bfce = 0x46;
  return;
}
