/* FUN_80164fc8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164fc8  body 0x80164fc8..0x801651ab  size 484 B
 * body sha256 d03695344f8249fb17bc2db74f60fd2cb3dcf83c3c5337644a550fb73d747fdd
 * provider record sha256 bf0c337759a93adcc689f6acf6565d8bfc5c49d637e297582dabc7ddf4df77cd
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164fc8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (*(char *)((int)param_1 + 0x2d9) == '\0') {
    if (*(char *)((int)param_1 + 6) == '\0') {
      *(undefined2 *)((int)param_1 + 6) = 0x100;
      _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
      uVar1 = func_0x80033144(param_1,&DAT_800e1130);
      param_1[0x7a] = ((uVar1 & 0xff) + (uint)*(byte *)((int)param_1 + 0x2cd) * 0xd + 3) * 0x1000000
      ;
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x400);
      param_1[0xaa] = 0;
      *(undefined2 *)(param_1 + 0xab) = 0;
      if (*(char *)((int)param_1 + 0x2d9) == '\0') {
        *(undefined1 *)((int)param_1 + 0x2c1) = 6;
        *(undefined1 *)((int)param_1 + 0x2c3) = 3;
      }
      if (((uint)*(byte *)((int)param_1 + 0x26e) % 3 == 0) &&
         (*(char *)((int)param_1 + 0x2d9) == '\0')) {
        uVar1 = func_0x80033604(param_1);
        uVar1 = (uVar1 & 1) << 2 | 3;
      }
      else {
        uVar1 = 10;
      }
      FUN_80166b98(param_1,uVar1,0);
      func_0x80077d18(0xb,param_1);
      *param_1 = *param_1 & 0xfffffffb;
    }
    else {
      func_0x800334c8(param_1,param_2,param_3,0);
      iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
      if (iVar2 == 0) {
        func_0x80032b5c(param_1,0);
      }
      else {
        uVar1 = 0x1090000;
        if (*(char *)((int)param_1 + 0x2d9) == '\0') {
          uVar1 = 0x1010000;
        }
        param_1[1] = uVar1;
        uVar3 = 0xfce0;
        if (*(char *)((int)param_1 + 0x2cd) == '\0') {
          uVar3 = 800;
        }
        *(undefined2 *)(param_1 + 0x4c) = uVar3;
      }
    }
  }
  else {
    FUN_80164e88();
  }
  return;
}
