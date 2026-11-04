/* FUN_801629ec
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x801629ec  body 0x801629ec..0x80162ae7  size 252 B
 * body sha256 12145f56ad2321d54a33c3e53985b1779ae8b13b2438925d112cf9025e2290a5
 * provider record sha256 e8b37bfa4cfc71848a8c9c67baeaafebd273f238d98617287bce36066fcc85ec
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801629ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  ushort uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    func_0x80077d18(6,param_1);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar2 & 0x1f) + 0x1e;
    FUN_80162d8c(param_1,*(byte *)(param_1 + 0x1ab) & 1,0);
    *(undefined4 *)(param_1 + 4) = 0x1070000;
    *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  }
  *(undefined2 *)(param_1 + 0x1e0) = 0x1e;
  *(undefined2 *)(param_1 + 0x1e4) = 0;
  *(undefined2 *)(param_1 + 0x1e2) = 0;
  func_0x80032b5c(param_1,0x800);
  return;
}
