/* scene_load_state
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800271d4  body 0x800271d4..0x800274e3  size 784 B
 * body sha256 a75efd6833e544b6cf5b7137b27ec98695fd7a4c568c7cfb708643cd395b044e
 * provider record sha256 9f5c825949f78a9f3ce72ca5f99ee405efa16d7fa41b49976369c2888df11a09
 * callees 20 direct (20 in corpus)
 * provider Ghidra 12.2
 */
void scene_load_state(void)

{
  undefined4 uVar1;
  
  if (DAT_80112968 == '\x01') {
    FUN_800270a8();
  }
  if ((DAT_800e10ec & 0x10000) == 0) {
    FUN_800276a8(1);
  }
  FUN_8006b3dc(1,0,2);
  FUN_80025130();
  if ((DAT_800e10ec & 0x200) == 0) {
    DAT_800e9183 = 0;
  }
  FUN_80026820();
  if (DAT_801127e0 != 0) {
    FUN_8006bccc(0);
    FUN_8006bd38(0);
  }
  uVar1 = func_0x800072e0();
  DAT_801127e0 = DAT_801127e0 + 1;
  func_0x80007300(uVar1);
  FUN_80026834(1,4);
  FUN_8006b6b4();
  FUN_8006b3dc(2,0,1);
  FUN_800267a4(2,FUN_80025350,4);
  FUN_8006b3dc(2,0,2);
  FUN_8006b6b4();
  FUN_8006b3dc(3,0,1);
  FUN_800267a4(3,FUN_80025600,3);
  FUN_8006b3dc(3,0,2);
  FUN_80026820();
  FUN_8006bc40(0);
  if (DAT_80112788 != 0) {
    osSendMesg(&DAT_80112a24,0,0);
    DAT_80112788 = DAT_80112788 + -1;
  }
  FUN_8006bb0c(DAT_800e9182);
  FUN_8006bbbc();
  if (DAT_801344c0 == 1) {
    DAT_801344c0 = 2;
  }
  uVar1 = func_0x800072e0();
  if (DAT_801127e0 == 2) {
    func_0x8000e350(0);
  }
  DAT_800c56f4 = DAT_800c56f4 == '\0';
  func_0x80007300(uVar1);
  if (DAT_801344c0 == 2) {
    overlay_open(0);
    FUN_80026a88();
    DAT_800c4f60 = 1;
    DAT_801344c0 = 0;
    DAT_800c56f4 = DAT_8010b6e4 == 0;
  }
  FUN_80026834(3,4);
  FUN_8006b6b4();
  FUN_8007849c();
  FUN_80026834(5,8);
  FUN_80026834(6,8);
  DAT_800e9104 = DAT_80112a1c - DAT_800e9100;
  DAT_800e9100 = DAT_80112a1c;
  uVar1 = func_0x800072e0();
  DAT_80112780 = 0;
  FUN_8006b3dc(0,0,1);
  (&DAT_80112968)[DAT_80112780] = 1;
  DAT_80112969 = 1;
  func_0x80007300(uVar1);
  DAT_800dfbe8 = DAT_800dfbe8 ^ 1;
  return;
}
