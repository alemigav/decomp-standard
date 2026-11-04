/* FUN_80162a6c
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162a6c  body 0x80162a6c..0x80162b9b  size 304 B
 * body sha256 847b1882583d761ae9849a313bf9c6fd2355e7c0bfeeb9aefcae3b942c3586a2
 * provider record sha256 64771e4cfa223b789aab45abceeda91e6dab0d656e5fb4612ce4d6a622f79b41
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80162a6c(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 == 0) {
    uVar3 = *(uint *)(param_1 + 0x28c);
    iVar4 = -0x7ff1eed0;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
    iVar4 = _DAT_800e13ec;
  }
  uVar1 = 0;
  if ((((uVar3 < *(ushort *)(iVar4 + 0x136) + 10) &&
       (uVar1 = 0, (uint)(*(int *)(iVar4 + 0x2c) - *(int *)(param_1 + 0x2c)) < 3000)) &&
      (uVar1 = 0, *(char *)(param_1 + 0x2bd) == '\0')) &&
     (uVar1 = 0, (*(byte *)(iVar4 + 0x26f) & 0x80) == 0)) {
    if (param_2 == 0) {
      uVar2 = func_0x80033144(param_1,iVar4);
      FUN_80162c6c(iVar4,uVar2);
      func_0x80059e00(1,1);
      func_0x80052bd0(3,0);
    }
    else {
      func_0x80080e00(param_1,1,1);
    }
    FUN_80162b9c(param_1,0,1);
    uVar1 = 1;
    *(undefined1 *)(param_1 + 0x2bd) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0x5a;
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
  }
  return uVar1;
}
