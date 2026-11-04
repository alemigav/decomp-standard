/* FUN_800aeccc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aeccc  body 0x800aeccc..0x800aedbf  size 244 B
 * body sha256 df4ee86a694045160a07116cca8ba76eb2e702a6be3a19f852e65b24d7b5f543
 * provider record sha256 9aca84607a10888efa257fdb8a33fa785339cc6f79cdcae37d14911e519cbd84
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800aeccc(void)

{
  char cVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (DAT_80147a58 != 0) {
    do {
      iVar4 = uVar5 * 4;
      cVar1 = (char)uVar5;
      uVar5 = uVar5 + 1;
      (&DAT_801588c0)[iVar4] = cVar1 + -1;
      *(char *)(iVar4 + -0x7fea773f) = (char)uVar5;
      uVar2 = (uint)DAT_80147a58;
      *(undefined2 *)(iVar4 + -0x7fea773e) = 1;
    } while (uVar5 < uVar2);
  }
  uVar2 = 0;
  DAT_801588c0 = 0xff;
  *(undefined1 *)((DAT_80147a58 - 1) * 4 + -0x7fea773f) = 0xff;
  DAT_80158a40 = 0;
  uVar5 = (uint)DAT_80147a58;
  DAT_80158839 = DAT_80147a58 - 1;
  if (uVar5 != 0) {
    iVar4 = -0x7fea77c0;
    do {
      *(undefined2 *)(iVar4 + 2) = 0;
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar2 < uVar5);
  }
  puVar3 = (undefined1 *)0x80158940;
  uVar5 = 0;
  do {
    *puVar3 = 0xff;
    uVar2 = uVar5 + 1;
    puVar3 = (undefined1 *)(uVar5 + 0x80158941);
    uVar5 = uVar2;
  } while (uVar2 < 0x100);
  _DAT_8015883a = 0xffff;
  DAT_8015883c = 0;
  DAT_80158838 = 0;
  return;
}
