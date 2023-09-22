TECSGEN = tecsgen
TARGET = sample
BASE_DIR = .
GEN_DIR = $(BASE_DIR)/gen
TECSGEN_FLAGS =


all: $(TARGET)

$(TARGET):$(TECSGEN)

$(TECSGEN):
	#cd ../../..
	#source set_env.sh
	$(TECSGEN) $(TECSGEN_FLAGS) sample.cdl

clean: 
	rm -r $(GEN_DIR)