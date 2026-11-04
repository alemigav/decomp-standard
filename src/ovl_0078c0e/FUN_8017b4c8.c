/* FUN_8017b4c8
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017b4c8  body 0x8017b4c8..0x8017b57f  size 184 B
 * body sha256 cd41d14f205a0a443f06c91ed3c09ead461688e1144217e0e2a4866010a1d911
 * provider record sha256 1471c87964ea9f5770acdde361ace05778a884b118908ce768a014bf25282971
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017b4c8(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  pbVar4 = &DAT_801803f0 + (ushort)(&DAT_801806dc)[param_1];
LAB_8017b4fc:
  do {
    for (; *pbVar4 < 0xee; pbVar4 = pbVar4 + 1) {
      if (*pbVar4 < 0x57) {
        iVar5 = iVar5 + *(char *)((uint)*pbVar4 * 2 + -0x7ff0613f);
      }
      else {
        iVar5 = iVar5 + 0xe;
      }
    }
    pbVar1 = &DAT_80180980;
    uVar2 = 0;
    do {
      if (*pbVar4 == *pbVar1) {
        if (uVar2 == 0) {
          return 0x140U - iVar5 >> 1;
        }
        pbVar4 = pbVar4 + 2;
        goto LAB_8017b4fc;
      }
      uVar3 = uVar2 + 1;
      pbVar1 = &DAT_80180981 + uVar2;
      uVar2 = uVar3;
    } while (uVar3 < 6);
    pbVar4 = pbVar4 + 1;
  } while( true );
}
