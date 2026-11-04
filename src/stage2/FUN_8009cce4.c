/* FUN_8009cce4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009cce4  body 0x8009cce4..0x8009ce3f  size 348 B
 * body sha256 02780449d9ef382fa00373d065827cafee2535f047224d7679b519455a502e12
 * provider record sha256 811857bf97fc54bf2e36a6750144f6741ae93a4abb2cf78d3cbeaa1b50a102e8
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009cce4(void)

{
  bool bVar1;
  int iVar2;
  undefined2 local_18 [4];
  
  _DAT_80012820 = DAT_8010b6f8;
  while( true ) {
    bVar1 = false;
    iVar2 = FUN_8002767c(0);
    if ((iVar2 == 0) && (DAT_800e9184 != 0x7fff)) {
      iVar2 = FUN_8002767c(3);
      bVar1 = iVar2 == 0;
    }
    if (!bVar1) break;
    FUN_8004cd88(1);
  }
  FUN_8006c070(0);
  FUN_8004cd88(1);
  if ((DAT_800e110c & 0x20) != 0) {
    func_0x80004b5c();
  }
  local_18[0] = 0xffff;
  DAT_80119ea0 = local_18;
  FUN_80076c84();
  FUN_80075da0();
  DAT_800e90f8 = 1;
  DAT_800e110c = DAT_800e110c & 0xffffffef;
  FUN_800274e4(2,1);
  FUN_80026040();
  FUN_80026980(0xc);
  DAT_800e920a = 0;
  DAT_800e9208 = 0xffff;
  FUN_800777d8(0x1007800);
  DAT_80012888 = 0x78;
  FUN_8004cec4(0);
  FUN_8004cdd4();
  return;
}
