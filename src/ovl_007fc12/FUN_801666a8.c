/* FUN_801666a8
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x801666a8  body 0x801666a8..0x80166787  size 224 B
 * body sha256 2d1bebaa560ce30b9b600ffd79735796640da7b83d9c87379921d1c9902d9555
 * provider record sha256 b9e8976e4f8526571d4387ae2ab20a79f35efb15bd28d672ef1fb12a079f718d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801666a8(uint *param_1)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    param_1[0x7a] = 0;
    func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x100);
    if ((param_1[0x9c] & 0x10000) != 0) {
      *(undefined1 *)((int)param_1 + 6) = 1;
      param_1[0x7a] = 0;
    }
  }
  else if (*(char *)((int)param_1 + 6) == '\x01') {
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar1 = func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x100);
    if (iVar1 != 0) {
      param_1[1] = 0x1050600;
      *(undefined1 *)((int)param_1 + 0x207) = 0;
      *(undefined1 *)((int)param_1 + 0x206) = 0;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbfff;
      *param_1 = *param_1 & 0xfffffff7;
    }
    func_0x80032b5c(param_1,0);
  }
  return;
}
