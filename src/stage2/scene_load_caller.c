/* scene_load_caller
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002616c  body 0x8002616c..0x80026523  size 952 B
 * body sha256 77828c7bd6b0bea6adc48492efb5e8e49e405743e97ce52ab5aca68b4e21ae67
 * provider record sha256 04fe700fa07baf61bb1737b0eb773f47e4b022377f2ea4d872ce87196fc5941c
 * callees 20 direct (20 in corpus)
 * provider Ghidra 12.2
 */
void scene_load_caller(void)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = (int)DAT_800df8b0 + 0x7ff38940 >> 3;
  if (DAT_800e90e8 < iVar2) {
    DAT_800e90e8 = iVar2;
  }
  iVar2 = (int)DAT_800df8b4 + 0x7ff2f020 >> 3;
  if (DAT_800e90ec < iVar2) {
    DAT_800e90ec = iVar2;
  }
  iVar2 = (int)DAT_800df8b8 + 0x7ff21ba0 >> 3;
  if (DAT_800e90f0 < iVar2) {
    DAT_800e90f0 = iVar2;
  }
  DAT_800df8b0 = &DAT_800c76c0;
  DAT_800df8b4 = &DAT_800d0fe0;
  DAT_800df8b8 = &DAT_800de460;
  if ((DAT_800e10ec & 0x1000) != 0) {
    FUN_800260d0();
    return;
  }
  if (((((DAT_800e10ec & 0x40000000) == 0) || (DAT_800e9183 != '\0')) || (DAT_80131780 != '\0')) ||
     ((((DAT_800e1110 & 0x1000000) != 0 || ((DAT_800e10ec & 0x2202200) != 0)) ||
      (((DAT_800e110c & 0x100010) != 0 || (DAT_800e9242 == '\0')))))) {
    DAT_800e9240 = '\0';
    if (DAT_800e9242 == '\0') goto LAB_80026380;
  }
  else {
    if (1 < DAT_800e9240) {
      uVar1 = ~CONCAT11(DAT_800df8bc._2_1_,(undefined1)DAT_800df8bc);
      DAT_800e9246 = uVar1 & (DAT_800e9244 ^ uVar1);
      DAT_800e9244 = uVar1;
      if ((DAT_800e9246 & 0x800) != 0) {
        FUN_800788ac(1);
        DAT_800e9242 = '\0';
      }
      DAT_80112975 = 0;
      DAT_80112974 = 0;
      FUN_8006bb0c(0);
      FUN_8006bbbc();
      return;
    }
    if (DAT_800e9240 == 0) {
      FUN_8004a7c8(0x87,0x6b,0,0x4000,"Paused");
    }
    DAT_800e9240 = DAT_800e9240 + 1;
    if (DAT_800e9242 != '\0') {
      FUN_800788ac(0);
      goto LAB_80026390;
    }
LAB_80026380:
    FUN_8005280c();
  }
  DAT_800e9242 = '\0';
LAB_80026390:
  FUN_8008456c();
  FUN_8004c9d4();
  DAT_800e90e4 = FUN_8008b028();
  FUN_8004ca84();
  if (DAT_800e90f8 == 0) {
    if (DAT_800e90f4 != 0) {
      if (DAT_800e90fc < 0x3d) {
        DAT_800e90f4 = 0;
      }
      else {
        FUN_800882d4(0);
        DAT_800e90fc = 0;
        DAT_800e90f4 = 0;
      }
    }
  }
  else {
    FUN_80088334(0);
    DAT_800e90fc = 0;
    DAT_800e90f4 = 0;
    DAT_800e90f8 = 0;
  }
  DAT_800e90fc = DAT_800e90fc + 1;
  DAT_800e110c = DAT_800e110c & 0xffcfffff;
  if ((DAT_800e10ec & 0x10000) == 0) {
    FUN_8004afbc();
    scene_load_state();
    func_0x80004a50();
  }
  else {
    iVar2 = FUN_8002767c(0);
    if (iVar2 != 0) {
      FUN_800275c0(0,0x1f,0x8080800,0);
      DAT_800e9194 = 0x8080810;
      FUN_8006ba18(0);
    }
    FUN_80043620();
    DAT_800df8b8 = (undefined *)FUN_80046f98(DAT_800df8b8,&DAT_800e9190);
    DAT_800e9184 = DAT_800e9184 - 2;
    if ((int)((uint)DAT_800e9184 << 0x10) < 0) {
      DAT_800e10ec = DAT_800e10ec & 0xfffeffff;
      FUN_8006ba18(1);
    }
    scene_load_state();
  }
  return;
}
