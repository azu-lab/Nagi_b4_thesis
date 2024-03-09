TECSGEN = tecsgen
TARGET = ErrorCaseSample
# TARGET = most_simple_sample
BASE_DIR = .
GEN_DIR = $(BASE_DIR)/gen
# GEN_DIR = $(BASE_DIR)/gen_most_simple
TECSGEN_FLAGS =


all: $(TARGET)

$(TARGET):$(TECSGEN)

$(TECSGEN):
	$(TECSGEN) $(TECSGEN_FLAGS) ErrorCaseSample.cdl

# simple: $(TARGET_SIMPLE)
# $(TARGET_SIMPLE):$(TECSGEN)

# $(TECSGEN):
# 	$(TECSGEN) $(TECSGEN_FLAGS) most_simple_sample.cdl

clean: 
	rm -r $(GEN_DIR)