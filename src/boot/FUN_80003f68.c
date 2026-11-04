/* FUN_80003f68
 * image   boot (boot), base 0x80000480
 * address 0x80003f68  body 0x80003f68..0x800040d3  size 364 B
 * body sha256 2097f733d7c4e8011046eafb681242e4bf388ec383e06b0a22b2c2d9a691edd9
 * provider record sha256 8508a62f713d60ab6e029528720c2dde183ead835fac36b8f463cea089ceb724
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80003f68(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 *param_6,undefined4 *param_7,int param_8)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_800038f0(param_3,param_1,0x101,0x800125e4,0x80012660,param_6,param_4,param_8);
  if (iVar1 != 0) {
    if (iVar1 == -3) {
      uVar2 = 0x8001181c;
    }
    else {
      if (iVar1 != -5) {
        return iVar1;
      }
      FUN_800042f4(*param_6,param_8);
      uVar2 = 0x80011840;
    }
    *(undefined4 *)(param_8 + 0x18) = uVar2;
    return -3;
  }
  iVar1 = FUN_800038f0(param_3 + param_1 * 4,param_2,0,0x800126dc,0x80012754,param_7,param_5,param_8
                      );
  if (iVar1 == 0) {
    return 0;
  }
  if (iVar1 == -3) {
    uVar2 = 0x8001181c;
  }
  else {
    if (iVar1 != -5) goto LAB_80004094;
    iVar1 = -3;
    FUN_800042f4(*param_7,param_8);
    uVar2 = 0x80011840;
  }
  *(undefined4 *)(param_8 + 0x18) = uVar2;
LAB_80004094:
  FUN_800042f4(*param_6,param_8);
  return iVar1;
}
