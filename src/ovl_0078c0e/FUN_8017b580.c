/* FUN_8017b580
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017b580  body 0x8017b580..0x8017b62f  size 176 B
 * body sha256 c968ed14860518c337956dba397bd44094a52df104636b8cced286dc586028ee
 * provider record sha256 ec0b0782683196368a54d8a420df2ac6e2a067206b732322253e0eca355a362f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017b580(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  pbVar4 = &DAT_801803f0 + (ushort)(&DAT_801806dc)[param_1];
LAB_8017b5b4:
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
          return iVar5;
        }
        pbVar4 = pbVar4 + 2;
        goto LAB_8017b5b4;
      }
      uVar3 = uVar2 + 1;
      pbVar1 = &DAT_80180981 + uVar2;
      uVar2 = uVar3;
    } while (uVar3 < 6);
    pbVar4 = pbVar4 + 1;
  } while( true );
}
