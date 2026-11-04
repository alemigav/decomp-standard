/* FUN_80163c44
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163c44  body 0x80163c44..0x80163dd7  size 404 B
 * body sha256 f9a04aa8be57782a5b9ffe878d52865435f5d82a4a29e81ace4d3f9a767af1fe
 * provider record sha256 d14c61870970e2c2cf0208ac2c0500217bcd251cedd9ed9d5c25e8d5423d3267
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163c44(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
      if (iVar2 == 0) {
        return;
      }
      *(undefined2 *)(param_1 + 6) = 0x200;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x8003f00;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 0x2b8) = 0;
    *(ushort *)(param_1 + 0x66) =
         *(short *)(param_1 + 0x66) + (ushort)*(byte *)(param_1 + 0x2cd) * 0x800;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    DAT_800e1135 = 1;
    DAT_800e1136 = 0;
    DAT_800e1137 = 0;
    _DAT_800e1196 = *(short *)(param_1 + 0x66) + 0x800;
    _DAT_800e10ec = _DAT_800e10ec | 0x4000100;
    func_0x80052bd0(3,0);
    func_0x80052bd0(4,8);
    func_0x80052bd0(3,0x14);
    func_0x80052c6c(0x14,200,0);
    func_0x80052d10(0x1e,200,0x32,0x14);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 7) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9003f00;
  }
  return;
}
