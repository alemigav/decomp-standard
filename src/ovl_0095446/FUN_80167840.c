/* FUN_80167840
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80167840  body 0x80167840..0x8016796b  size 300 B
 * body sha256 1d123cb8275399481ced9b0d57c0bd5ebadca4a8e083449e9c2067d41458dba1
 * provider record sha256 7626ceebe52a87c66db6876d47eca2db305b31d3cfdaa4decf0c86118f576ff0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167840(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 5) * 0x1000000 + 0x300;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    uVar2 = 0x4010000;
    if (*(char *)(param_1 + 5) == '\0') {
      uVar2 = 0x4000000;
    }
    func_0x80077adc(uVar2 | 1,param_1 + 0x28);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined1 *)(param_1 + 0x25c) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    _DAT_800e110c = _DAT_800e110c & 0xffffffbf;
  }
  func_0x80032b5c(param_1,0);
  return;
}
