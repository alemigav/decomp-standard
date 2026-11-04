/* FUN_80164c98
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164c98  body 0x80164c98..0x80164d17  size 128 B
 * body sha256 2f3bdbaa1354f2e5ecc0adcd54bbf93cfde149b9148608816732016fc5ac2c25
 * provider record sha256 4b818fa1a8bb4809a39c5ef24ada23aff6f89a29a9bf5d7ae447dec9801123d3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164c98(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xc000000;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    func_0x80089d54();
    *(undefined1 *)(param_1 + 0x2c1) = 8;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
  }
  iVar1 = func_0x800837ac(0x800e8ce0,0x5f);
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}
