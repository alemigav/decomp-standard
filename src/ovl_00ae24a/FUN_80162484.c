/* FUN_80162484
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80162484  body 0x80162484..0x8016255b  size 216 B
 * body sha256 df41bc65529895108c5e85130188e4dcc60e05dbfa4ba8d7f9a793058527bbd7
 * provider record sha256 13bf7d4369a5a5f44c19a48a5a030fcd37af918247b90bb80d39195707ea4a52
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162484(int param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x28c);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x80);
  if ((((9000 < *(int *)(param_1 + 0x28)) && (uVar2 < 6000)) && (sVar1 == 0)) &&
     (((DAT_800e139f == 0 && (_DAT_800e1322 < 1)) && ((*(ushort *)(param_1 + 0x2c2) & 4) == 0)))) {
    *(undefined4 *)(param_1 + 4) = 0x1040000;
    func_0x80059e00(500,0);
    DAT_800e139f = DAT_800e139f | 0x80;
    *(undefined1 *)(param_1 + 0x2b4) = 4;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    _DAT_800e10ec = _DAT_800e10ec | 0x100;
  }
  return;
}
