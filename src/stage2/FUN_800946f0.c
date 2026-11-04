/* FUN_800946f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800946f0  body 0x800946f0..0x800948ab  size 444 B
 * body sha256 eaf93e997f619c97da5dceab7b8c6877d23aaff40b788a6c90ce4b8e95dc875f
 * provider record sha256 d6d70a8e01c134e9dae54082820ef46e3c53631f5d3a227fe0215bba0f693047
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800946f0(void)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined **ppuVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  
  iVar6 = 0xe;
  puVar2 = (undefined4 *)&DAT_8013a3d8;
  do {
    *puVar2 = 0;
    iVar6 = iVar6 + -1;
    puVar2 = puVar2 + -1;
  } while (-1 < iVar6);
  if (DAT_8012fe04 == '\0') {
    uVar3 = (uint)(byte)(&DAT_800e8ff4)[DAT_8012bfa9 * 8 + (int)(char)DAT_8012bfaa];
    ppuVar4 = &PTR_DAT_8012fcc0;
  }
  else {
    iVar6 = (int)((uint)DAT_8012bfaa << 0x18) >> 0x18;
    uVar3 = iVar6 - ((int)((uint)DAT_8012bfaa << 0x18) >> 0x1f) >> 1;
    if ((iVar6 + uVar3 * -2 & 0xff) == 0) {
      uVar3 = (uint)((byte)(&DAT_800e9013)[uVar3 & 0xff] >> 4);
    }
    else {
      uVar3 = (byte)(&DAT_800e9013)[uVar3 & 0xff] & 0xf;
    }
    ppuVar4 = &PTR_DAT_8012fdc4;
  }
  pcVar7 = &DAT_8017b410;
  uVar3 = func_0x80004cfc(*(undefined2 *)(ppuVar4[uVar3] + (uint)DAT_8012bfab * 2),&DAT_8017b410,0,
                          "FILE TXT");
  pcVar5 = &DAT_8017b410 + (uVar3 & 0xffff);
  iVar6 = 0;
  if (&DAT_8017b410 < pcVar5) {
    puVar2 = (undefined4 *)&DAT_8013a3a0;
    _DAT_8013a3a0 = &DAT_8017b410;
    bVar1 = true;
    while( true ) {
      puVar2 = puVar2 + 1;
      iVar6 = iVar6 + 1;
      if (!bVar1) break;
      do {
        bVar1 = pcVar7 < pcVar5;
        if (*pcVar7 == '\r') break;
        pcVar7 = pcVar7 + 1;
        bVar1 = false;
      } while (pcVar7 < pcVar5);
      if (!bVar1) break;
      if (*pcVar7 == '\r') {
        *pcVar7 = '\0';
        pcVar7 = pcVar7 + 2;
      }
      bVar1 = pcVar7 < pcVar5;
      if (!bVar1) break;
      *puVar2 = pcVar7;
    }
  }
  if (iVar6 < 0xf) {
    *pcVar7 = '\0';
  }
  else {
    FUN_8004cdd4();
    *pcVar7 = '\0';
  }
  return;
}
