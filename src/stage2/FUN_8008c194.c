/* FUN_8008c194
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c194  body 0x8008c194..0x8008c25b  size 156 B
 * body sha256 f7802fc9d7b773d8c474d4cab77de7cba85117ac2ab9919663a2152be4b115b8
 * provider record sha256 649597ca97977689634144a8967ea6b905fa1a5b710b13411a946f217e7552e0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c194(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  switch(DAT_800e8ca8) {
  case 1:
    iVar2 = 0x1e;
    break;
  case 2:
    iVar2 = 0x3a;
    break;
  case 3:
    iVar2 = 0x48;
    break;
  case 4:
    iVar2 = 0x59;
    break;
  case 5:
    iVar2 = 99;
    break;
  case 6:
    iVar2 = 0x7b;
  }
  FUN_80083758(&DAT_800e8d98,iVar2 + DAT_800e8caa);
  uVar1 = FUN_80091738((int)DAT_800e8ca8,(int)DAT_800e8caa);
  FUN_80083758(&DAT_800e8d94,uVar1);
  return;
}
