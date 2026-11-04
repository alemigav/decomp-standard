/* FUN_8004ca84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ca84  body 0x8004ca84..0x8004cbf3  size 368 B
 * body sha256 e3670e12af3cb32cf16f7dc7160344741546fdd2ee1c4b65f38ecf312b091f73
 * provider record sha256 a874c6ca9df27e61b20dc730f15f648fde35171745ebf3c0fcfcb28dfcf7ef10
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ca84(void)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  undefined1 auStack_30 [8];
  
  iVar6 = 0;
  puVar5 = &DAT_8010b328;
  do {
    if (1 < iVar6) {
      return;
    }
    uVar1 = *puVar5;
    DAT_8010b6b8 = puVar5;
    if (uVar1 == 2) {
      uVar3 = func_0x800072e0();
      puVar2 = DAT_8010b6b8;
      iVar4 = func_0x80007010(&DAT_80112bf0);
      osCreateThread(DAT_8010b6b8 + 4,*(undefined4 *)(puVar2 + 0xde),*(undefined4 *)(puVar2 + 0xdc)
                      ,0,*(undefined4 *)(puVar2 + 0xe0),iVar4 + 1);
      func_0x80007300(uVar3);
LAB_8004cb94:
      *DAT_8010b6b8 = 0x7f;
      osStartThread(DAT_8010b6b8 + 4);
      osRecvMesg(0x80139b30,auStack_30,1);
    }
    else if (uVar1 < 3) {
      if ((uVar1 == 1) &&
         (uVar1 = puVar5[1], puVar5[1] = uVar1 - 1, (int)((uint)(ushort)(uVar1 - 1) << 0x10) < 1))
      goto LAB_8004cb94;
    }
    else if (uVar1 == 4) goto LAB_8004cb94;
    puVar5 = puVar5 + 0xe4;
    iVar6 = iVar6 + 1;
  } while( true );
}
